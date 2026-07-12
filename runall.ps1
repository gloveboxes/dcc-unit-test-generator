<#!
.SYNOPSIS
Run archived tests in parallel and compare DCC output with Clang baselines.

.DESCRIPTION
Use -UpdateBaseline to generate archive/baselines from Clang. The default
mode builds and runs every archived test through DCC and ntvcm, then compares
normalized stdout with its batch-specific baseline.
#>
[CmdletBinding()]
param(
    [Parameter(Position = 0)]
    [string]$Selection = "all",
    [switch]$UpdateBaseline,
    [ValidateSet("fast", "nopeep", "full")]
    [string]$Mode = "fast",
    [switch]$Serial,
    [switch]$KeepBuild,
    [int]$Jobs = [Environment]::ProcessorCount,
    [string]$Clang = "",
    [string]$Ntvcm = "",
    [string]$BaselineRoot = "archive/baselines",
    [string]$BuildRoot = ".archive-build",
    [string]$LogsRoot = "/tmp/dcc-archive-logs"
)

$ErrorActionPreference = "Stop"
$repoRoot = (Resolve-Path $PSScriptRoot).Path
Set-Location $repoRoot

if (-not $Clang) {
    $Clang = if ($env:CLANG) { $env:CLANG } else { "clang" }
}
if (-not $Ntvcm) {
    $Ntvcm = if ($env:NTVCM) { $env:NTVCM }
    elseif ($env:NTVCM_DIR) { Join-Path $env:NTVCM_DIR "ntvcm" }
    else { "ntvcm" }
}
if ($env:ARCHIVE_BASELINES_DIR) { $BaselineRoot = $env:ARCHIVE_BASELINES_DIR }
if ($env:ARCHIVE_BUILD_DIR) { $BuildRoot = $env:ARCHIVE_BUILD_DIR }
if ($env:ARCHIVE_LOGS_DIR) { $LogsRoot = $env:ARCHIVE_LOGS_DIR }
if ($env:ARCHIVE_JOBS -and -not $Serial) { $Jobs = [int]$env:ARCHIVE_JOBS }
if ($Serial) { $Jobs = 1 }
if ($Jobs -lt 1) { throw "Jobs must be at least 1." }

function Get-Standard([string]$BaseName) {
    if ($BaseName -like "c89*") { return "c89" }
    if ($BaseName -like "c99*") { return "c99" }
    return "c11"
}

function Get-TestDirectories([string]$Requested) {
    if ($Requested -eq "all") {
        return @(Get-ChildItem -Path (Join-Path $repoRoot "archive") -Directory -Filter "batch*" |
            Sort-Object { [int]$_.Name.Substring(5) })
    }
    if ($Requested -match '^[0-9]+$') {
        $Requested = "archive/batch$Requested"
    }
    $path = Join-Path $repoRoot $Requested
    if (-not (Test-Path -LiteralPath $path -PathType Container)) {
        throw "Batch directory not found: $Requested"
    }
    return @((Get-Item -LiteralPath $path))
}

function Normalize-Output([AllowNull()][string]$Text) {
    if ($null -eq $Text) { return "" }
    return (($Text -replace "`r`n", "`n") -replace "`r", "`n").TrimEnd("`n")
}

$directories = Get-TestDirectories $Selection
$items = foreach ($directory in $directories) {
    Get-ChildItem -LiteralPath $directory.FullName -File -Filter "c*.c" |
        Sort-Object Name | ForEach-Object {
            [pscustomobject]@{
                Batch = $directory.Name
                Source = $_.FullName
                Base = $_.BaseName
                Key = "$($directory.Name)/$($_.BaseName)"
            }
        }
}
if ($items.Count -eq 0) { throw "No C programs found for selection '$Selection'." }

$runItems = foreach ($item in $items) {
    $modes = if ($Mode -eq "full") { @("fast", "nopeep") } else { @($Mode) }
    foreach ($runMode in $modes) {
        [pscustomobject]@{
            Batch = $item.Batch
            Source = $item.Source
            Base = $item.Base
            Key = "$($item.Key) [$runMode]"
            Mode = $runMode
        }
    }
}
$runItems = @($runItems)
$results = $runItems | ForEach-Object -Parallel {
    $item = $_

    function Invoke-ProcessCapture {
        param(
            [string]$FilePath,
            [string[]]$Arguments,
            [string]$WorkingDirectory,
            [int]$TimeoutSeconds
        )
        $start = [Diagnostics.ProcessStartInfo]::new()
        $start.FileName = $FilePath
        $start.WorkingDirectory = $WorkingDirectory
        $start.UseShellExecute = $false
        $start.RedirectStandardOutput = $true
        $start.RedirectStandardError = $true
        foreach ($argument in $Arguments) { [void]$start.ArgumentList.Add($argument) }
        $process = [Diagnostics.Process]::new()
        $process.StartInfo = $start
        if (-not $process.Start()) { throw "Could not start $FilePath" }
        $stdoutTask = $process.StandardOutput.ReadToEndAsync()
        $stderrTask = $process.StandardError.ReadToEndAsync()
        if (-not $process.WaitForExit($TimeoutSeconds * 1000)) {
            try { $process.Kill($true) } catch { }
            return [pscustomobject]@{ ExitCode = 124; TimedOut = $true; Stdout = $stdoutTask.Result; Stderr = $stderrTask.Result }
        }
        $process.WaitForExit()
        return [pscustomobject]@{ ExitCode = $process.ExitCode; TimedOut = $false; Stdout = $stdoutTask.Result; Stderr = $stderrTask.Result }
    }

    function Write-Utf8NoBom([string]$Path, [string]$Text) {
        $encoding = [Text.UTF8Encoding]::new($false)
        [IO.File]::WriteAllText($Path, $Text, $encoding)
    }

    function Normalize-WorkerOutput([AllowNull()][string]$Text) {
        if ($null -eq $Text) { return "" }
        return (($Text -replace "`r`n", "`n") -replace "`r", "`n").TrimEnd("`n")
    }

    function Get-WorkerStandard([string]$BaseName) {
        if ($BaseName -like "c89*") { return "c89" }
        if ($BaseName -like "c99*") { return "c99" }
        return "c11"
    }

    function Get-BaselinePath {
        return Join-Path (Join-Path $using:BaselineRoot $item.Batch) "$($item.Base).txt"
    }

    $baseline = Get-BaselinePath
    $logDirectory = Join-Path $using:LogsRoot $item.Batch
    New-Item -ItemType Directory -Force -Path $logDirectory | Out-Null
    $baseLog = Join-Path $logDirectory "$($item.Base).$($item.Mode)"
    $logPath = if ($using:UpdateBaseline) { "$baseLog.clang.log" } else { "$baseLog.dcc.log" }
    $success = $false
    $detail = ""

    if ($using:UpdateBaseline) {
        New-Item -ItemType Directory -Force -Path (Split-Path $baseline) | Out-Null
        $hostPath = "$baseLog.host"
        $compile = Invoke-ProcessCapture $using:Clang @("-std=$(Get-WorkerStandard $item.Base)", "-Wall", "-Wextra", "-pedantic", "-fsigned-char", $item.Source, "-o", $hostPath) $using:repoRoot 90
        Write-Utf8NoBom $logPath ($compile.Stdout + $compile.Stderr)
        if ($compile.ExitCode -eq 0) {
            $run = Invoke-ProcessCapture $hostPath @() $using:repoRoot 30
            Add-Content -LiteralPath $logPath -Value ($run.Stderr) -NoNewline
            if ($run.ExitCode -eq 0) {
                Write-Utf8NoBom $baseline (Normalize-WorkerOutput $run.Stdout)
                $success = $true
            }
        }
        Remove-Item -LiteralPath $hostPath -Force -ErrorAction SilentlyContinue
    }
    else {
        $buildDirectory = Join-Path (Join-Path (Join-Path $using:BuildRoot $item.Batch) $item.Base) $item.Mode
        $rawPath = "$baseLog.dcc.raw"
        $actualPath = "$baseLog.actual"
        Remove-Item -LiteralPath $buildDirectory, $rawPath, $actualPath -Recurse -Force -ErrorAction SilentlyContinue
        New-Item -ItemType Directory -Force -Path $buildDirectory | Out-Null
        if (-not (Test-Path -LiteralPath $baseline -PathType Leaf)) {
            Write-Utf8NoBom $logPath "missing baseline: $baseline`n"
        }
        else {
            $outputName = $item.Base.ToUpperInvariant()
            $dccArguments = @("dcc-input=$($item.Source)", "dcc-output=$outputName", "dcc-build-dir=$buildDirectory")
            if ($item.Mode -eq "nopeep") { $dccArguments += "dcc-peep=false" }
            $build = Invoke-ProcessCapture "dccmake" $dccArguments $using:repoRoot 90
            Write-Utf8NoBom $logPath ($build.Stdout + $build.Stderr)
            if ($build.ExitCode -eq 0) {
                $comPath = Join-Path $buildDirectory "$outputName.COM"
                $run = Invoke-ProcessCapture $using:Ntvcm @($comPath) $using:repoRoot 30
                Add-Content -LiteralPath $logPath -Value ($run.Stderr) -NoNewline
                if ($run.ExitCode -eq 0) {
                    Write-Utf8NoBom $rawPath $run.Stdout
                    Write-Utf8NoBom $actualPath (Normalize-WorkerOutput $run.Stdout)
                    $expected = Normalize-WorkerOutput ([IO.File]::ReadAllText($baseline))
                    $actual = Normalize-WorkerOutput ([IO.File]::ReadAllText($actualPath))
                    if ($expected -ceq $actual) { $success = $true }
                    else {
                        Add-Content -LiteralPath $logPath -Value "`n--- expected ---`n$expected`n`n--- actual ---`n$actual"
                    }
                }
            }
        }
        Remove-Item -LiteralPath $rawPath, $actualPath -Force -ErrorAction SilentlyContinue
        if ($success -or -not $using:KeepBuild) {
            Remove-Item -LiteralPath $buildDirectory -Recurse -Force -ErrorAction SilentlyContinue
        }
    }

    [pscustomobject]@{
        Key = $item.Key
        Success = $success
        Label = if ($using:UpdateBaseline) { if ($success) { "BASELINE" } else { "BASELINE FAIL" } } elseif ($success) { "PASS" } else { "FAIL" }
        Log = $logPath
    }
} -ThrottleLimit $Jobs

$failureCount = 0
foreach ($result in @($results) | Sort-Object Key) {
    if (-not $result.Success) { $failureCount++ }
    $suffix = if ($result.Success) { "" } else { " (see $($result.Log))" }
    Write-Host "$($result.Label) $($result.Key)$suffix"
}

$passed = $runItems.Count - $failureCount
Write-Host "`narchive $Mode results: $passed passed, $failureCount failed, $($runItems.Count) total"

if ($failureCount -ne 0) { exit 1 }
if (-not $KeepBuild) {
    Remove-Item -LiteralPath $BuildRoot -Recurse -Force -ErrorAction SilentlyContinue
}