# Fixed dcc regression: automatic LCS table recurrence produced wrong result

**Status:** Fixed and regression-verified 2026-07-10.

## Fix verification

The original automatic-storage source in `c8918.c` now compiles and runs
correctly with dcc. No source workaround was applied.

```sh
./validate-examples.sh all
```

The complete 100-test suite passed every applicable strict Clang mode and all
dcc/ntvcm builds. In particular, the original regression now prints
`c8918 lcs=3` and exits with status 0.

## Summary

dcc accepts, assembles, and links a valid C89 longest-common-subsequence program, but the generated CP/M program computes `1` instead of `3`. Clang produces the expected result under C89, C99, and C11. Disabling `dccpeep` does not change the failure, so the defect occurs before peephole optimization.

The failure follows the nontrivial recurrence over an automatic table. Rewriting the conditional expression as `if`/`else` does not help, and flattening the automatic table does not help. Moving the same two-dimensional table to static storage does help. A simpler 81-element automatic-array fill and sum passes, so this is not merely an automatic-array size limit.

The original regression source remains unchanged in `c8918.c`.

## Complete reproduction

```c
#include <stdio.h>
#define MAXLEN 8

static int lcs(const char *a, const char *b)
{
    int table[MAXLEN + 1][MAXLEN + 1];
    int i, j, na = 0, nb = 0;

    while (a[na])
        ++na;
    while (b[nb])
        ++nb;

    for (i = 0; i <= na; ++i)
        table[i][0] = 0;
    for (j = 0; j <= nb; ++j)
        table[0][j] = 0;

    for (i = 1; i <= na; ++i)
        for (j = 1; j <= nb; ++j)
            table[i][j] = a[i - 1] == b[j - 1]
                ? table[i - 1][j - 1] + 1
                : (table[i - 1][j] > table[i][j - 1]
                    ? table[i - 1][j]
                    : table[i][j - 1]);

    return table[na][nb];
}

int main(void)
{
    int actual = lcs("ABCDGH", "AEDFHR");
    printf("c8918 lcs=%d\n", actual);
    return actual != 3;
}
```

The strings have the LCS `ADH`, whose length is 3.

## Oracle

```sh
clang -std=c89 -Wall -Wextra -pedantic -fsigned-char \
    examples/c8918.c -o /tmp/c8918
/tmp/c8918
```

Expected output and exit status:

```text
c8918 lcs=3
exit status 0
```

The same source also passes Clang with `-std=c99` and `-std=c11`.

## dcc reproduction

```sh
dccmake dcc-input=examples/c8918.c dcc-output=C8918 \
    dcc-build-dir=bc8918
ntvcm bc8918/C8918.COM
```

Actual dcc/ntvcm output and exit status:

```text
c8918 lcs=1
exit status 1
```

The build completes without compiler, assembler, or linker errors.

With peephole optimization disabled:

```sh
dccmake dcc-input=examples/c8918.c dcc-output=C8918 \
    dcc-build-dir=/tmp/bnpc8918 dcc-peep=false
ntvcm /tmp/bnpc8918/C8918.COM
```

The result is still:

```text
c8918 lcs=1
exit status 1
```

## Isolation matrix

| Variant | dcc/ntvcm result | Outcome |
| --- | --- | --- |
| Original automatic `int table[9][9]` recurrence | `lcs=1` | Fail |
| Replace nested conditional expression with equivalent `if`/`else` | `value=1` | Fail |
| Flatten table to automatic `int table[81]` | `value=0` | Fail |
| Move original two-dimensional table to static storage | `value=3` | Pass |
| Simple automatic `int a[81]` fill and sum | `value=3240` | Pass |
| Simple automatic `int a[3][3]` dynamic fill and sum | `sum=99` | Pass |
| Original source with `dcc-peep=false` | `lcs=1` | Fail |

These results rule out the nested conditional operator, multidimensional syntax alone, array size alone, and `dccpeep` as sole causes. They point to dcc code generation for this indexed dynamic-programming recurrence when its working table has automatic storage duration.

## Workaround

Declaring the table with static storage duration produces the correct result:

```c
#define MAXLEN 8
static int table[MAXLEN + 1][MAXLEN + 1];
```

This workaround is documented for compiler isolation only. It has **not** been applied to `c8918.c`; the original valid automatic-storage form is intentionally preserved as a regression test.

## Expected dcc behavior

dcc should generate a CP/M program that prints:

```text
c8918 lcs=3
```

and exits with status 0, with or without peephole optimization.
