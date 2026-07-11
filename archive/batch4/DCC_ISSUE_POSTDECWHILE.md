# dcc issue: post-decrement while condition rejected

Status: open. Clang accepts the valid C99 bit-rotation helper, but dcc rejects
the `while (count--)` condition before code generation.

Affected test: `c9915.c`.

## Application

The test implements a bounded 16-bit rotate-left helper. The loop count is a
local integer that is tested and decremented by the standard post-decrement
operator on each iteration. This is a conventional, readable C implementation
of a fixed-count bit operation.

## Observed diagnostic

```text
examples/c9915.c:2: error DCC-E1002: unsupported while condition or body near 'while'
```

The rejected expression is:

```c
while (count--) {
    value = (value << 1) | ((value & mask) != 0);
    value &= 65535;
}
```

## Oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char \
    examples/c9915.c -o /tmp/c9915 && /tmp/c9915
```

Expected output:

```text
c9915 rotate=16,1
```

## Possible compiler-side direction

The dcc statement generator should support a scalar post-decrement expression
as the controlling expression of a `while` statement, preserving C semantics:
use the old value for the truth test, then store the decremented value. A
source-level workaround would be:

```c
while (count > 0) {
    value = (value << 1) | ((value & mask) != 0);
    value &= 65535;
    --count;
}
```

That workaround is intentionally not applied. The original expression is valid
C99 and remains useful for exposing the unsupported dcc control-flow form. Once
accepted, dcc should produce the same output as Clang under ntvcm.
