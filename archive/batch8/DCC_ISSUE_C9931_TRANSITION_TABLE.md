# dcc issue: two-dimensional transition-table indexing rejected

**Status:** Fixed and verified on 2026-07-10

**Affected test:** `c9931.c`

## Summary

dcc rejects ordinary indexing of a file-scope, two-dimensional constant transition table. The table uses small enum indices and valid C99 designated initializers. Changing the element type from `enum State` to `int` does not resolve the rejection. An explicit transition function works correctly.

## Minimal reproduction

```c
enum State { IDLE, RUNNING, STOPPED };
enum Event { START, STOP };

static const enum State transitions[3][2] = {
    [IDLE] = {[START] = RUNNING, [STOP] = IDLE},
    [RUNNING] = {[START] = RUNNING, [STOP] = STOPPED},
    [STOPPED] = {[START] = RUNNING, [STOP] = STOPPED}
};

int main(void)
{
    enum State state;
    state = transitions[IDLE][START];
    state = transitions[state][STOP];
    return state != STOPPED;
}
```

## Actual dcc result

```text
error DCC-E1002: unsupported expression statement near 'state'
    state = transitions[IDLE][START];
    ^
error DCC-E1002: unsupported expression statement near 'state'
    state = transitions[state][STOP];
    ^
```

dcc does not produce assembly.

## Isolation matrix

| Variant | dcc result |
| --- | --- |
| `const enum State transitions[3][2]` indexed twice | Fails with `DCC-E1002` |
| `const int transitions[3][2]` indexed twice | Fails with `DCC-E1002` |
| Explicit `next_state(state, event)` function | Passes and exits 0 |
| Original enum table under Clang C99 | Passes and exits 0 |

## Workaround

Use an explicit transition function:

```c
static enum State next_state(enum State state, enum Event event)
{
    if (event == START) return RUNNING;
    if (state == RUNNING) return STOPPED;
    return state;
}
```

This keeps the state machine readable, although the data-driven table is also a conventional and valid implementation.

## Clang oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char repro.c -o /tmp/repro
/tmp/repro
```

**Expected output:** no output

**Expected exit status:** `0`

## Expected dcc result

dcc should compile both transition-table reads, transition from `IDLE` to `RUNNING` on `START`, then from `RUNNING` to `STOPPED` on `STOP`, and produce a CP/M program that exits with status `0` under ntvcm.

## Fix verification

The original two-dimensional enum transition table remains in `c9931.c`. The complete `./validate-examples.sh all` run reports `dcc ok c9931` and finishes with `validation ok`.
