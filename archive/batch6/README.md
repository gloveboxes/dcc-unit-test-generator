# Active dcc test batch

This directory contains the active batch of 100 standalone programs for the dcc compiler targeting CP/M 2.2 on the Z80.

## Test split

- `c89*.c`: 34 strict C89 tests covering calendars, intervals, integer and fixed-point arithmetic, checksums, bit operations, numeric predicates, and bounded string/array routines.
- `c99*.c`: 33 C99 tests covering designated initializers, compound literals, `stdbool.h`, variably modified array parameters, `restrict`, inline functions, variadic functions, and matrix/vector-style routines.
- `c11*.c`: 33 C11 tests covering anonymous structures and unions, tagged values, bit-fields, register and packet overlays, compact instructions, and result/state records.

Every program prints a deterministic result and returns zero. Filenames use CP/M-compatible 8.3 names without underscores.

## Validation

Run the Clang oracle:

```sh
./validate-examples.sh clang
```

Run the complete Clang plus dcc/ntvcm validation:

```sh
./validate-examples.sh all
```

The suite was checked with both commands. The complete validation finished with `validation ok`; no dcc issue report was required for this batch.

## Target constraints

The tests respect the dcc Z80 model: 16-bit `int`, `short`, pointers, and `size_t`; 32-bit `long`; signed `char`; 32-bit `float`; and no `double` or `long long`. They avoid unsupported library dependencies and keep data sets small enough for CP/M execution.
