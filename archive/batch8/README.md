# Active CP/M Z80 C test batch

This directory contains 100 standalone unit-test programs for dcc targeting CP/M 2.2 on the Z80. The programs favor bounded storage, explicit contracts, deterministic behavior, and maintainable implementations suitable for a 16-bit system.

Each program prints one line beginning with its filename and returns zero only when its behavioral checks pass. The validator therefore checks compilation, linking, and runtime behavior under ntvcm.

## Test split

- 34 strict C89 tests (`c8901.c` through `c8934.c`)
- 33 C99 tests (`c9901.c` through `c9933.c`)
- 33 C11 tests (`c1101.c` through `c1133.c`)

## Coverage

The C89 tests cover bounded queues and heaps, stable sorting, binary search, interval merging, checksums, parsers, fixed-point arithmetic, matrices, state machines, object pools, search structures, dynamic programming, bit sets, and number-theory routines.

The C99 tests use designated initializers, compound literals, `stdbool.h`, fixed-width integers, bounded VLAs, `restrict` kernels, `static inline` helpers, base-type-safe variadic functions, formatting, bit-fields, and data-driven configuration.

The C11 tests focus on anonymous structures and unions used in tagged results, events, commands, messages, optional values, protocol headers, register overlays, coordinates, matrices, packed dates, counters, and other compact system records.

## Target constraints

- CP/M-compatible 8.3 filenames with no underscores
- 16-bit `int`, pointers, and `size_t`
- 32-bit `long`; no `long long`
- Signed 8-bit `char`; explicit `unsigned char` for raw bytes
- No `double`, unsupported hosted APIs, threads, atomics, `_Generic`, or `_Static_assert`
- Small fixed arrays and bounded VLAs to protect the shared Z80 stack and heap
- Explicit casts for portable fixed-width integer formatting
- Little-endian assumptions documented on byte-overlay unions

## dcc issues discovered

The active tests retain the original valid C constructs as regression checks. All four defects have been fixed in dcc and verified by the complete validation suite.

| Affected test | Issue report | Status |
| --- | --- | --- |
| `c8934.c` | [Indexed struct-member compound assignment](DCC_ISSUE_C8934_INDEXED_COMPOUND.md) | Fixed and verified |
| `c9907.c` | [Complex predicate rejected in a for loop](DCC_ISSUE_C9907_COMPLEX_FOR.md) | Fixed and verified |
| `c9930.c` | [For-init loop variable causes wrong runtime result](DCC_ISSUE_C9930_FOR_SCOPE_RUNTIME.md) | Fixed and verified |
| `c9931.c` | [Two-dimensional transition-table indexing rejected](DCC_ISSUE_C9931_TRANSITION_TABLE.md) | Fixed and verified |

The initial `c9920.c` failure was not a compiler defect. Its original API accepted 45,296 seconds through a 16-bit `int`; the corrected test uses `long` and `45296L` and passes on both host and target.

## Validation

Run the host oracle:

```sh
./validate-examples.sh clang
```

Run dcc and execute every COM program under ntvcm:

```sh
./validate-examples.sh dcc
```

Run both stages:

```sh
./validate-examples.sh all
```

The complete batch passes `./validate-examples.sh all` with the original regression forms intact and finishes with `validation ok`.
