#!/usr/bin/env sh
# Run archived tests in parallel and compare DCC output with Clang baselines.
set -u

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$script_dir"

clang_bin=${CLANG:-clang}
ntvcm_bin=${NTVCM:-${NTVCM_DIR:-/Users/dave/GitHub/ntvcm}/ntvcm}
baseline_root=${ARCHIVE_BASELINES_DIR:-archive/baselines}
build_root=${ARCHIVE_BUILD_DIR:-.archive-build}
logs_root=${ARCHIVE_LOGS_DIR:-/tmp/dcc-archive-logs}
jobs=${ARCHIVE_JOBS:-$(getconf _NPROCESSORS_ONLN 2>/dev/null || printf '1')}
mode=verify
selection=all
keep_build=0
failures=0
total=0

usage() {
    cat >&2 <<EOF
usage: $0 [--update-baseline] [--serial] [--keep-build] [all|batch-number|archive/batch-directory]

Generate Clang baselines with --update-baseline, or verify DCC/ntvcm output
against archive/baselines by default. Override parallelism with ARCHIVE_JOBS.
EOF
    exit 2
}

run_to() {
    _timeout=$1
    shift
    perl -e '
        my $timeout = shift @ARGV;
        my $pid = fork();
        if ($pid == 0) { setpgrp(0, 0); exec(@ARGV); exit 127; }
        $SIG{ALRM} = sub { kill("KILL", -$pid); };
        alarm($timeout);
        waitpid($pid, 0);
        exit($? >> 8 ? ($? >> 8) : ($? & 127 ? 124 : 0));
    ' "$_timeout" "$@"
}

standard_for() {
    case "$1" in
        c89*) printf 'c89' ;;
        c99*) printf 'c99' ;;
        c11*) printf 'c11' ;;
        *)    printf 'c11' ;;
    esac
}

baseline_path() {
    printf '%s/%s/%s.txt' "$baseline_root" "$1" "$2"
}

run_clang() {
    batch_dir=$1
    src=$2
    batch=$(basename "$batch_dir")
    base=$(basename "$src" .c)
    baseline=$(baseline_path "$batch" "$base")
    log="$logs_root/$batch/$base.clang.log"
    host="$logs_root/$batch/$base.host"
    raw="$logs_root/$batch/$base.clang.raw"
    mkdir -p "$(dirname "$baseline")" "$(dirname "$log")"

    if "$clang_bin" "-std=$(standard_for "$base")" -Wall -Wextra -pedantic -fsigned-char \
            "$src" -o "$host" >"$log" 2>&1 \
            && run_to 30 "$host" </dev/null >"$raw" 2>>"$log"; then
        tr -d '\r' <"$raw" >"$baseline"
        rm -f "$host" "$raw"
        return 0
    fi
    rm -f "$baseline" "$host" "$raw"
    return 1
}

run_dcc() {
    batch_dir=$1
    src=$2
    batch=$(basename "$batch_dir")
    base=$(basename "$src" .c)
    upper=$(printf '%s' "$base" | tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    build_dir="$build_root/$batch/$base"
    baseline=$(baseline_path "$batch" "$base")
    log="$logs_root/$batch/$base.dcc.log"
    raw="$logs_root/$batch/$base.dcc.raw"
    actual="$logs_root/$batch/$base.actual"
    rm -rf "$build_dir" "$raw" "$actual"
    mkdir -p "$build_dir" "$(dirname "$log")"

    if [ ! -f "$baseline" ]; then
        printf 'missing baseline: %s\n' "$baseline" >"$log"
        return 1
    fi
    if run_to 90 dccmake "dcc-input=$src" "dcc-output=$upper" \
            "dcc-build-dir=$build_dir" </dev/null >"$log" 2>&1 \
            && run_to 30 "$ntvcm_bin" "$build_dir/$upper.COM" </dev/null \
                >"$raw" 2>>"$log"; then
        tr -d '\r' <"$raw" >"$actual"
        if cmp -s "$baseline" "$actual"; then
            rm -f "$raw" "$actual"
            if [ "$keep_build" -eq 0 ]; then rm -rf "$build_dir"; fi
            return 0
        fi
    fi
    if [ -f "$baseline" ] && [ -f "$actual" ]; then
        printf '\n--- expected ---\n' >>"$log"
        cat "$baseline" >>"$log"
        printf '\n--- actual ---\n' >>"$log"
        cat "$actual" >>"$log"
    fi
    rm -f "$raw" "$actual"
    return 1
}

run_one() {
    batch_dir=$1
    src=$2
    batch=$(basename "$batch_dir")
    base=$(basename "$src" .c)
    if [ "$mode" = update ]; then
        run_clang "$batch_dir" "$src"
        result=$?
        label=BASELINE
        log_suffix=clang
    else
        run_dcc "$batch_dir" "$src"
        result=$?
        label=PASS
        log_suffix=dcc
    fi
    if [ "$result" -eq 0 ]; then
        printf '%s %s/%s\n' "$label" "$batch" "$base"
    else
        [ "$mode" = update ] && label='BASELINE FAIL' || label=FAIL
        printf '%s %s/%s (see %s)\n' "$label" "$batch" "$base" \
            "$logs_root/$batch/$base.$log_suffix.log"
    fi
    return "$result"
}

launch_group() {
    batch_dir=$1
    pids=''
    count=0
    for src in "$batch_dir"/c*.c; do
        [ -f "$src" ] || continue
        total=$((total + 1))
        run_one "$batch_dir" "$src" &
        pids="$pids $!"
        count=$((count + 1))
        if [ "$count" -ge "$jobs" ]; then
            for pid in $pids; do
                wait "$pid" || failures=$((failures + 1))
            done
            pids=''
            count=0
        fi
    done
    for pid in $pids; do
        wait "$pid" || failures=$((failures + 1))
    done
}

while [ "$#" -gt 0 ]; do
    case "$1" in
        --update-baseline) mode=update ;;
        --serial) jobs=1 ;;
        --keep-build) keep_build=1 ;;
        --help|-h) usage 2>/dev/null; exit 0 ;;
        all|[0-9]*|archive/batch*) selection=$1 ;;
        *) usage ;;
    esac
    shift
done

if [ "$selection" = all ]; then
    batch_dirs=''
    for batch_dir in archive/batch*; do
        [ -d "$batch_dir" ] || continue
        batch_dirs="$batch_dirs $batch_dir"
    done
else
    case "$selection" in
        [0-9]*) batch_dirs="archive/batch$selection" ;;
        *)      batch_dirs="$selection" ;;
    esac
fi

for batch_dir in $batch_dirs; do
    if [ ! -d "$batch_dir" ]; then
        printf 'batch directory not found: %s\n' "$batch_dir" >&2
        failures=$((failures + 1))
        continue
    fi
    launch_group "$batch_dir"
done

passed=$((total - failures))
printf '\narchive %s results: %d passed, %d failed, %d total\n' \
    "$mode" "$passed" "$failures" "$total"

if [ "$failures" -ne 0 ]; then
    exit 1
fi
if [ "$keep_build" -eq 0 ]; then
    rm -rf "$build_root"
fi