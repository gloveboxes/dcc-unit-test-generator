# dcc C test suite

This directory contains the current batch of 50 standalone programs for dcc
targeting CP/M 2.2 on Z80:

- `c8901.c` through `c8917.c`: 17 strict C89 tests
- `c9901.c` through `c9917.c`: 17 C99 tests
- `c1101.c` through `c1116.c`: 16 C11 tests

The programs are intentionally written like small production utilities rather
than language-feature puzzles. Each has a narrow responsibility, named helper
functions, bounded storage, deterministic inputs, and one name-prefixed output
line. The suite covers parsing, checksums, searching, sorting, dynamic
programming, graph traversal, scheduling-style containers, matrix operations,
record processing, VLA APIs, `restrict` kernels, compound values, variadic
helpers, tagged unions, anonymous aggregates, bit-fields, and overlays.

C89 sources use declarations at block starts and only C89 syntax. C99 sources
exercise designated initializers, compound literals, `stdbool.h`, VLAs,
`restrict`, `static inline`, and variadic functions. C11 sources focus on
anonymous struct/union promotion, tagged payloads, bit-fields, and explicit
aggregate initialization. No test uses `_Generic`, `_Static_assert`, `double`,
`long long`, or unsupported library facilities.

All filenames follow CP/M 8.3 rules and contain no underscore because the
M80/L80 toolchain rejects underscored output names.

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

The active suite is discovered from `examples/c*.c`. Earlier generated batches
are preserved in `archive/`, including the immediately previous batch in
`archive/batch3/`.

## Current result

The current 50-test batch passes the Clang oracle. Forty-eight tests also pass
dcc/ntvcm. Two Clang-valid tests expose dcc front-end issues and remain
unchanged as regressions:

| Report | Test | Issue |
| --- | --- | --- |
| [DCC_ISSUE_MATRIXLOOP.md](DCC_ISSUE_MATRIXLOOP.md) | `c9908` | Nested matrix `for` statements rejected |
| [DCC_ISSUE_POSTDECWHILE.md](DCC_ISSUE_POSTDECWHILE.md) | `c9915` | Post-decrement `while` condition rejected |

The compiler was not modified and neither test was rewritten to hide the
failure.
