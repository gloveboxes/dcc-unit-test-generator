# DCC C Compiler unit test generator

This repository is a workspace for generating unit tests for the DCC C
Compiler, which targets CP/M 2.2 on the Z80. It produces standalone C89, C99,
and C11 programs that test language features, library behavior, algorithms,
data structures, and target-specific edge cases.

Generated tests use Clang as the source-validity oracle, then run through the
DCC toolchain and the [ntvcm](https://github.com/davidly/ntvcm) emulator. Valid
C accepted by Clang is preserved when it exposes a DCC defect, making the test
a compiler regression case rather than weakening it to accommodate the bug.

The repository currently contains a feature-heavy generation target in
`main.c` and 900 generated test programs organized into 11 archived batches.

## Prerequisites

- A POSIX shell environment
- Clang, for host-side conformance checks
- Perl, used by the validation scripts to enforce timeouts
- A local dcc checkout containing `dcc`, `dccmake`, `dccpeep`,
  `dccrtlstrip`, `DCCRTL.MAC`, `m80.com`, and `l80.com`
- A local ntvcm checkout containing the `ntvcm` executable

Set the toolchain locations before building:

```sh
export DCC_DIR="$HOME/GitHub/dcc"
export NTVCM_DIR="$HOME/GitHub/ntvcm"
export PATH="$DCC_DIR:$NTVCM_DIR:$PATH"
```

`dccmake.txt` supplies the build settings for `main.c`, including floating
point and long integer I/O, stack checking, and an 8 KiB stack.

## Build the generation target

Build `main.c`, copy the resulting `MAIN.COM` to the repository root, and run
it under ntvcm:

```sh
./build-app.sh
```

The program exercises a broad cross-section of DCC behavior, including C99
designated initializers and compound literals, C11 anonymous aggregates,
bit-fields, function pointers, variadic functions, `setjmp`/`longjmp`,
single-precision floating point, and target data-model reporting.

## Validate generated tests

Build and execute all archived generated programs through DCC and ntvcm:

```sh
./run-archive-batches.sh
```

Run one batch by number or path:

```sh
./run-archive-batches.sh 1
./run-archive-batches.sh archive/batch10
```

Each build has a 90-second timeout and each execution has a 30-second timeout.
Logs are written to `/tmp/dcc-archive-logs` by default. Override the working
and log locations with `ARCHIVE_BUILD_DIR` and `ARCHIVE_LOGS_DIR`; override the
emulator with `NTVCM` or `NTVCM_DIR`.

The runner exits nonzero if any program fails and prints a pass/fail summary at
the end.

For a parallel run with output verification against Clang-generated baselines
using PowerShell 7:

```sh
pwsh ./runall.ps1 -UpdateBaseline   # regenerate archive/baselines with Clang
pwsh ./runall.ps1                   # build/run DCC tests in parallel and compare
pwsh ./runall.ps1 -Mode nopeep      # run without peephole optimization
pwsh ./runall.ps1 -Mode full        # run both optimized and unoptimized builds
pwsh ./runall.ps1 10                # verify one batch
pwsh ./runall.ps1 -Serial           # sequential fallback for debugging
```

### Run modes

`runall.ps1` accepts one optimization mode for each test run:

| Mode | DCC build | Tests per source |
| --- | --- | ---: |
| `fast` | Peephole optimization enabled; default mode | 1 |
| `nopeep` | Peephole optimization disabled with `dcc-peep=false` | 1 |
| `full` | Runs both `fast` and `nopeep` builds | 2 |

All modes compare output with the same Clang-generated baseline. Therefore a
complete `full` run executes 1,800 tests for the 900 archived source files:

```powershell
pwsh ./runall.ps1 -Mode fast       # 900 optimized runs
pwsh ./runall.ps1 -Mode nopeep     # 900 unoptimized runs
pwsh ./runall.ps1 -Mode full       # 1,800 runs: both variants
```

Baselines are keyed by batch and test name, so repeated names in different
archive batches do not collide. DCC build and emulator output is isolated per
test; failures retain logs in `/tmp/dcc-archive-logs` by default. Set
`ARCHIVE_JOBS` to change the concurrency limit and use `--keep-build` to retain
build artifacts for a failing test.

## Validate active examples

`validate-examples.sh` supports host-only, target-only, or combined validation
for standard-tagged programs placed in `examples`:

```sh
./validate-examples.sh clang
./validate-examples.sh dcc
./validate-examples.sh all
```

The `examples` directory is currently empty. Archived programs should be run
with `run-archive-batches.sh` instead.

## Generation conventions

Source names identify the language standard being exercised:

- `c89NN.c`: strict C89, also compiled by the host validator as C99 and C11
- `c99NN.c`: C99, also compiled by the host validator as C11
- `c11NN.c`: C11

Names remain CP/M 8.3-compatible and contain no underscores. Underscores in
M80/L80 object or output names can leave the legacy linker waiting at an
interactive prompt.

Generated tests account for the DCC target model: 16-bit `int`, pointers, and `size_t`;
32-bit `long`; 32-bit single-precision `float`; signed 8-bit `char`; and no
`double` or `long long`. Each program is standalone and returns zero when its
checks pass.

## Repository layout

| Path | Purpose |
| --- | --- |
| `main.c` | Comprehensive DCC feature generation target |
| `dccmake.txt` | dccmake configuration for `main.c` |
| `build-app.sh` | Build and run the demonstration |
| `examples/` | Working directory for the active 50-program suite |
| `validate-examples.sh` | Clang and dcc/ntvcm validation for active examples |
| `archive/` | Historical test batches |
| `run-archive-batches.sh` | dcc/ntvcm runner for archived batches |
| `runall.sh` | Parallel DCC runner with Clang output baselines |
| `runall.ps1` | Portable PowerShell 7 parallel runner with Clang baselines |

Generated build directories, `.COM` files, and test logs are not source
artifacts and can be removed after a run.