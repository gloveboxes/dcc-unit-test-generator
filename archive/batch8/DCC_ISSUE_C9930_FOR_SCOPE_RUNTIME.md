# dcc issue: for-init loop variable causes incorrect palindrome result

**Status:** Fixed and verified on 2026-07-10

**Affected test:** `c9930.c`

## Summary

dcc compiles a C99 palindrome function but generates incorrect runtime behavior when the comparison loop declares its index in the `for` initializer. Moving the same index declaration to function scope makes the program work. The failure occurs with both `bool` and `int` return types, so it is not a boolean normalization issue.

## Minimal reproduction

```c
#include <stdbool.h>

static bool palindrome(const char *text)
{
    int length = 0;
    while (text[length]) ++length;

    for (int i = 0; i < length / 2; ++i)
        if (text[i] != text[length - 1 - i]) return false;

    return true;
}

int main(void)
{
    return !palindrome("level");
}
```

## Actual dcc result

dcc compiles and links the program without a diagnostic, but the resulting COM program exits with status `1`. In the complete test, the observed output was:

```text
c9930 palindrome=0,0
```

The first result should be `1` because `"level"` is a palindrome.

## Isolation matrix

| Variant | dcc result |
| --- | --- |
| `for (int i = 0; ...)`, returning `bool` | Compiles, exits 1 |
| `for (int i = 0; ...)`, returning `int` | Compiles, exits 1 |
| Declare `int i;` before the loop, returning `bool` | Passes, exits 0 |
| Declare `int i;` before the loop, returning `int` | Passes, exits 0 |
| Original source under Clang C99 | Passes, exits 0 |

## Workaround

Declare the loop index before the `for` statement:

```c
static bool palindrome(const char *text)
{
    int length = 0;
    int i;

    while (text[length]) ++length;
    for (i = 0; i < length / 2; ++i)
        if (text[i] != text[length - 1 - i]) return false;
    return true;
}
```

This workaround retains the algorithm and avoids the code-generation defect.

## Clang oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char repro.c -o /tmp/repro
/tmp/repro
```

**Expected output:** no output

**Expected exit status:** `0`

## Expected dcc result

dcc should preserve the C99 loop variable's value and scope correctly, return `true` for `"level"`, and produce a CP/M program that exits with status `0` under ntvcm.

## Fix verification

The loop-scoped `for (int i = 0; ...)` form remains in `c9930.c`. The complete `./validate-examples.sh all` run reports `dcc ok c9930` and finishes with `validation ok`.
