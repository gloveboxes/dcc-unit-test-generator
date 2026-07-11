# dcc issue: valid complex predicate rejected in a for loop

**Status:** Fixed and verified on 2026-07-10

**Affected test:** `c9907.c`

## Summary

dcc rejects a C99 `for` loop whose body validates a character with a compound logical predicate. The same predicate works when expressed in a `while` loop with the current character materialized in a local variable. Clang accepts and correctly executes the original source.

## Minimal reproduction

```c
#include <stdbool.h>

static bool valid(const char *text)
{
    for (++text; *text; ++text)
        if (!((*text >= 'A' && *text <= 'Z') ||
              (*text >= 'a' && *text <= 'z') ||
              (*text >= '0' && *text <= '9')))
            return false;
    return true;
}

int main(void)
{
    return !valid("item42");
}
```

## Actual dcc result

```text
error DCC-E1002: unsupported for statement near 'for'
    for (++text; *text; ++text)
    ^
```

dcc does not produce assembly for the valid loop.

## Isolation matrix

| Variant | dcc result |
| --- | --- |
| Original `for` loop and compound predicate | Fails with `DCC-E1002` |
| Equivalent `while` loop with `char ch = *text` | Passes and exits 0 |
| Original source under Clang C99 | Passes and exits 0 |

## Workaround

Use a `while` loop and give the character expression a descriptive local name:

```c
static bool valid(const char *text)
{
    ++text;
    while (*text) {
        char ch = *text;
        if (!((ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') ||
              (ch >= '0' && ch <= '9')))
            return false;
        ++text;
    }
    return true;
}
```

## Clang oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char repro.c -o /tmp/repro
/tmp/repro
```

**Expected output:** no output

**Expected exit status:** `0`

## Expected dcc result

dcc should accept the original C99 `for` statement, return `true` for `"item42"`, and produce a CP/M program that exits with status `0` under ntvcm.

## Fix verification

The original `for` loop and compound predicate remain in `c9907.c`. The complete `./validate-examples.sh all` run reports `dcc ok c9907` and finishes with `validation ok`.
