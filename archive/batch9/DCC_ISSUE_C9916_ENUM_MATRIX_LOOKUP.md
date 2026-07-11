# Fixed dcc regression: repeated lookup through two-dimensional enum table was miscompiled

**Status:** Fixed and regression-verified 2026-07-10.

## Fix verification

The original two-dimensional enum-table source in `c9916.c` now compiles and
runs correctly with dcc. No source workaround was applied.

```sh
./validate-examples.sh all
```

The complete 100-test suite passed every applicable strict Clang mode and all
dcc/ntvcm builds. In particular, the original regression now prints
`c9916 machine=3` and exits with status 0.

## Summary

dcc accepts, assembles, and links a valid C99 finite-state machine, but the generated CP/M program finishes in state `1` instead of state `3`. Clang produces the expected state under C99 and C11. Disabling `dccpeep` does not change the failure, so the defect occurs before peephole optimization.

The table is initialized correctly: reading and printing every element produces `01 21 03 33`, exactly as declared. A single dynamically indexed lookup also works. The failure appears when an enum state is repeatedly updated through a two-dimensional enum table. Changing only the table element type to `int`, or flattening the enum table to one dimension, produces the correct result.

The test uses ordinary C enum types. It does not use `<stdint.h>` or C99 fixed-width integer typedefs. Its C99 feature is the nested designated initializer.

The original regression source remains unchanged in `c9916.c`.

## Complete reproduction

```c
#include <stdio.h>

enum State { S0, S1, S2, S3 };

static const enum State transition[4][2] = {
    [S0] = { [0] = S0, [1] = S1 },
    [S1] = { [0] = S2, [1] = S1 },
    [S2] = { [0] = S0, [1] = S3 },
    [S3] = { [0] = S3, [1] = S3 }
};

static enum State scan(const char *bits)
{
    enum State state = S0;

    for (; *bits; ++bits)
        state = transition[state][*bits - '0'];

    return state;
}

int main(void)
{
    enum State state = scan("1101");
    printf("c9916 machine=%d\n", (int)state);
    return state != S3;
}
```

The expected transitions are:

```text
S0 --1--> S1 --1--> S1 --0--> S2 --1--> S3
```

## Oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char \
    examples/c9916.c -o /tmp/c9916
/tmp/c9916
```

Expected output and exit status:

```text
c9916 machine=3
exit status 0
```

The same source also passes Clang with `-std=c11`.

## dcc reproduction

```sh
dccmake dcc-input=examples/c9916.c dcc-output=C9916 \
    dcc-build-dir=bc9916
ntvcm bc9916/C9916.COM
```

Actual dcc/ntvcm output and exit status:

```text
c9916 machine=1
exit status 1
```

The build completes without compiler, assembler, or linker errors.

With peephole optimization disabled:

```sh
dccmake dcc-input=examples/c9916.c dcc-output=C9916 \
    dcc-build-dir=/tmp/bnpc9916 dcc-peep=false
ntvcm /tmp/bnpc9916/C9916.COM
```

The result is still:

```text
c9916 machine=1
exit status 1
```

## Isolation matrix

| Variant | dcc/ntvcm result | Outcome |
| --- | --- | --- |
| Original designated `enum State transition[4][2]` scan | `machine=1` | Fail |
| Sequential initializer `{{S0,S1},{S2,S1},{S0,S3},{S3,S3}}` | `value=1` | Fail |
| Print all designated table elements | `01210333` | Pass |
| One lookup with variable row and column | `value=3` | Pass |
| One lookup with constant row and variable column | `value=3` | Pass |
| Same two-dimensional table with element type `int` | `value=3` | Pass |
| Flattened one-dimensional table with element type `enum State` | `value=3` | Pass |
| Original source with `dcc-peep=false` | `machine=1` | Fail |

The passing table dump rules out designated-initializer data emission. The sequential-initializer failure rules out designated syntax as the runtime trigger. The `int` and flattened variants isolate the failing form to repeated state updates through a two-dimensional enum array.

## Workarounds

Changing the table element type to `int` works:

```c
static const int transition[4][2] = {
    { S0, S1 }, { S2, S1 }, { S0, S3 }, { S3, S3 }
};

state = (enum State)transition[state][*bits - '0'];
```

Flattening the enum table also works:

```c
static const enum State transition[8] = {
    S0, S1, S2, S1, S0, S3, S3, S3
};

state = transition[(int)state * 2 + (*bits - '0')];
```

These workarounds are documented for compiler isolation only. Neither has been applied to `c9916.c`; the original valid two-dimensional enum form is intentionally preserved as a regression test.

## Expected dcc behavior

dcc should generate a CP/M program that prints:

```text
c9916 machine=3
```

and exits with status 0, with or without peephole optimization.
