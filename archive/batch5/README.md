# dcc CP/M Z80 C test suite

This directory contains the current 100-test batch for the dcc compiler and
CP/M 2.2 on Z80:

- `c8901.c` through `c8934.c`: 34 strict C89 tests
- `c9901.c` through `c9933.c`: 33 C99 tests
- `c1101.c` through `c1133.c`: 33 C11 tests

The split intentionally uses CP/M-safe 8.3 filenames with no underscores.
Each source is a standalone program with bounded memory use, deterministic
inputs, and one output line prefixed by its test name. The tests avoid `double`,
`long long`, host-sized assumptions, and unsupported runtime libraries.

## Coverage

The C89 programs exercise integer algorithms, parsing, checksums, binary
search, sorting, queues, graph-like traversal, dynamic programming, bit
operations, fixed-size string processing, and small numeric kernels.

The C99 programs exercise designated initializers, compound literals,
`stdbool.h`, VLAs, `restrict`, `static inline`, variadic functions, sparse
tables, matrix and vector operations, bounded buffer transforms, and explicit
record processing.

The C11 programs exercise anonymous struct and union promotion, tagged values,
bit-fields, register and address overlays, packet and command records, result
values, version fields, and other target-relevant data layouts.

All arrays and loops are deliberately small for dcc's 16-bit `int`, 16-bit
pointer, and CP/M transient-memory model. The C11 overlay tests assume the
little-endian layout shared by the Z80 target and the host oracle.

## Validation

Run the Clang oracle:

```sh
./validate-examples.sh clang
```

Run the dcc/CP/M pipeline:

```sh
./validate-examples.sh dcc
./validate-examples.sh all
```

The validator compiles C89 files as C89, C99, and C11; C99 files as C99 and
C11; and C11 files as C11. The dcc path builds each program with dccmake,
peephole optimization, runtime stripping, M80/L80, and ntvcm, with hard
timeouts around build and execution.

## Batch history

The immediately previous 50-test suite is preserved in `archive/batch4/`.
Earlier suites remain in their existing archive locations. Only `examples/c*.c`
is active for validation.

## Result

The current 100-test batch passes the Clang oracle and dcc/ntvcm validation.
No dcc compiler issues were found in this batch.
