# dcc issue: nested matrix loop rejected

Status: open. Clang accepts the valid C99 matrix multiplication program, but
dcc rejects its ordinary nested `for` statements before code generation.

Affected test: `c9908.c`.

## Application

The test multiplies two 2x2 integer matrices using three bounded loops. The
implementation keeps the matrix representation explicit and uses a local result
value, which is a normal maintainable C99 implementation for a small fixed-size
kernel.

## Observed diagnostic

```text
examples/c9908.c:3: error DCC-E1002: unsupported for statement near 'for'
```

The diagnostic points at the first loop in the nested loop chain:

```c
for (i = 0; i < 2; ++i)
    for (j = 0; j < 2; ++j)
        for (k = 0; k < 2; ++k)
            r.values[i][j] += a.values[i][k] * b.values[k][j];
```

## Oracle

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char \
    examples/c9908.c -o /tmp/c9908 && /tmp/c9908
```

Expected output:

```text
c9908 matrix=4,4/10,8
```

## Possible compiler-side direction

The dcc statement support path should accept nested ordinary `for` statements
when each loop has a declaration-free initializer, a relational condition, and
an increment expression. A temporary dcc-safe source shape would be:

```c
for (i = 0; i < 2; ++i) {
    for (j = 0; j < 2; ++j) {
        for (k = 0; k < 2; ++k) {
            r.values[i][j] += a.values[i][k] * b.values[k][j];
        }
    }
}
```

That workaround is not applied because the original test is valid C99 and
should remain the regression case. After the front end accepts the statement,
dcc should produce the same matrix result under ntvcm.
