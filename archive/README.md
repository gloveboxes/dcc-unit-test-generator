# dcc C test suite

This directory contains 50 standalone programs for dcc targeting CP/M 2.2 on
Z80:

- `c8901.c` through `c8917.c`: 17 strict C89 algorithm and data-structure tests
- `c9901.c` through `c9917.c`: 17 C99 feature and library tests
- `c1101.c` through `c1116.c`: 16 C11 anonymous struct/union and tagged-value tests

Every program has a deterministic, name-prefixed output line. Filenames follow
CP/M 8.3 rules and contain no underscore because the M80/L80 toolchain rejects
underscored output names.

The tests account for the dcc target model: 16-bit `int`, 32-bit `long`,
single-precision `float`, no `double` or `long long`, and the documented dcc
library subset. C99/C11 fixed-width values are cast to the matching `printf`
base type. C11 tests use anonymous aggregate member promotion, but do not use
unsupported `_Generic` or `_Static_assert`.

## Validation

Run the Clang oracle from the repository root:

```sh
./validate-examples.sh clang
```

The validator compiles every C89 source as C89, C99, and C11; every C99 source
as C99 and C11; and every C11 source as C11, with `-Wall -Wextra -pedantic`.

With `DCC_DIR` and `NTVCM_DIR` configured as described by the root
`dccmake.txt`, run the CP/M pipeline with:

```sh
./validate-examples.sh dcc
./validate-examples.sh all
```

The dcc path uses `dccmake`, `dccpeep`, `dccrtlstrip`, M80, L80, and ntvcm with
hard timeouts around each build and execution.

## Resolved dcc issues

The Clang and dcc/ntvcm validators are green for all 50 tests. Six tests exposed
three front-end defects in dcc; their valid source remains as a compiler
regression suite, and the fixes are now in the sibling dcc repository:

| Report | Tests | Defect |
| --- | --- | --- |
| [DCC_ISSUE_ANONDESIGN.md](DCC_ISSUE_ANONDESIGN.md) | `c1113`, `c1115` | Promoted anonymous-member designators |
| [DCC_ISSUE_NESTEDAGG.md](DCC_ISSUE_NESTEDAGG.md) | `c1106`, `c1112`, `c1114` | Nested anonymous aggregate brace handling |
| [DCC_ISSUE_CONSTPTRARRAY.md](DCC_ISSUE_CONSTPTRARRAY.md) | `c9901` | Const pointer-array element call argument |
