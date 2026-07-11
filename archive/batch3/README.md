# dcc C test suite

This directory contains the current batch of 50 standalone programs for dcc
 targeting CP/M 2.2 on Z80:

- `c8901.c` through `c8917.c`: 17 strict C89 algorithm and data-structure tests
- `c9901.c` through `c9917.c`: 17 C99 feature and library tests
- `c1101.c` through `c1116.c`: 16 C11 anonymous struct/union and tagged-value tests

Every program prints one deterministic result line beginning with its own base
name. Filenames follow CP/M 8.3 rules and contain no underscore because the
M80/L80 toolchain rejects underscored output names.

The C89 scenarios cover Roman numeral parsing, CRC-16, Luhn validation,
Josephus elimination, GCD reduction, base conversion, Bresenham line walking,
edit distance, prime sieving, postfix evaluation, ring buffers, determinants,
Tower of Hanoi, run-length analysis, rational arithmetic, grid paths, and
string hashing.

The C99 scenarios cover designated tables, compound literals, `stdbool.h`,
constant-stride VLA parameters, `restrict`, `static inline`, variadic sums,
sparse initializers, enum dispatch, packet construction, `sprintf`, and
additional VLA and fixed-width operations.

The C11 scenarios cover anonymous struct grouping, tagged unions, promoted
members, bit-field headers, IPv4 and register overlays, linked entries,
intervals, commands, values, and instruction payloads.

## Validation

Run the Clang oracle from the repository root:

```sh
./validate-examples.sh clang
```

The validator compiles every C89 source as C89, C99, and C11; every C99 source
as C99 and C11; and every C11 source as C11, with `-Wall -Wextra -pedantic`.

Run the dcc/CP/M pipeline with:

```sh
./validate-examples.sh dcc
./validate-examples.sh all
```

The dcc path uses `dccmake`, `dccpeep`, `dccrtlstrip`, M80, L80, and ntvcm with
hard timeouts around each build and execution.

## Batch history

The previously validated batch is preserved in `archive/batch2/`. The earlier
archived batch remains directly under `archive/`. Neither archive is used by
the validator; only `examples/c*.c` is active.

## Results

The current batch passed both the Clang oracle and dcc/ntvcm validation. No dcc
compiler issues were found in this batch. One authoring bug in the initial
Bresenham implementation caused a non-terminating Clang run; it was corrected
in `c8907.c` before the final validation.
