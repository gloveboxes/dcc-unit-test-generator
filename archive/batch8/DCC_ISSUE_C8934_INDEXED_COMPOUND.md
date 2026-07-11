# dcc issue: compound assignment through an indexed struct member

**Status:** Fixed and verified on 2026-07-10

**Affected test:** `c8934.c`

## Summary

dcc rejects a valid compound assignment when the left operand is an array element reached through a pointer to a structure. Clang accepts the C89 program and the program produces the expected bit-set value.

## Minimal reproduction

```c
struct BitSet {
    unsigned int words[2];
};

void add(struct BitSet *set, int value)
{
    set->words[value / 16] |= (unsigned int)(1U << (value % 16));
}

int main(void)
{
    struct BitSet set = {{0U, 0U}};
    add(&set, 20);
    return set.words[1] != 16U;
}
```

## Actual dcc result

```text
error DCC-E1002: unsupported expression statement near 'set'
    set->words[value / 16] |= (unsigned int)(1U << (value % 16));
    ^
```

dcc does not produce assembly for the translation unit.

## Isolation matrix

| Variant | dcc result |
| --- | --- |
| Direct compound OR assignment to the indexed element | Fails with `DCC-E1002` |
| Read element into a local, apply compound OR, write local back | Passes and exits 0 |
| Same original program under Clang C89 | Passes and exits 0 |

## Workaround

Split the read-modify-write operation into explicit steps:

```c
void add(struct BitSet *set, int value)
{
    int index = value / 16;
    unsigned int mask = (unsigned int)(1U << (value % 16));
    unsigned int word = set->words[index];

    word |= mask;
    set->words[index] = word;
}
```

This is maintainable and preserves the exact behavior, but the direct compound assignment is valid C and should not require rewriting.

## Clang oracle

```sh
clang -std=c89 -Wall -Wextra -pedantic -fsigned-char repro.c -o /tmp/repro
/tmp/repro
```

**Expected output:** no output

**Expected exit status:** `0`

## Expected dcc result

dcc should compile the direct indexed compound assignment, generate code that updates `words[1]` to `16`, and the resulting CP/M program should exit with status `0` under ntvcm.

## Fix verification

The original direct compound assignment remains in `c8934.c`. The complete `./validate-examples.sh all` run reports `dcc ok c8934` and finishes with `validation ok`.
