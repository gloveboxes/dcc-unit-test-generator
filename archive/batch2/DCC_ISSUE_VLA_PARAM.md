# dcc issue: variable inner dimension in a VLA parameter

Status: open. Clang accepts and runs valid C99 code using a two-dimensional
variable-length-array parameter, but dcc rejects the parameter declaration
before code generation.

Affected test: `c9912.c`.

## Application description

`c9912.c` calculates the sum of a rectangular integer matrix. The matrix has
two dimensions supplied at run time: `rows` is the number of rows and `cols`
is the number of columns. The function parameter uses the C99 VLA form
`int grid[rows][cols]`, which is adjusted to a pointer to rows whose stride is
the run-time value `cols * sizeof(int)`.

The function deliberately uses the inner VLA dimension because that is the
part of the C99 parameter model that dcc currently rejects. The test is small,
deterministic, and uses only the dcc-supported integer and stdio subset.

## Reproduction

```c
#include <stdio.h>

static int sum_rows(int rows, int cols, int grid[rows][cols])
{
    int r;
    int c;
    int total = 0;

    for (r = 0; r < rows; ++r)
        for (c = 0; c < cols; ++c)
            total += grid[r][c];

    return total;
}

int main(void)
{
    int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("c9912 vlamatrix=%d\n", sum_rows(2, 3, grid));
    return 0;
}
```

## Observed dcc diagnostic

```text
examples/c9912.c:2: error DCC-E0601: variable inner dimensions in variable-length arrays are not supported; use malloc and an explicit pointer near 'cols'
```

The diagnostic is emitted from `skip_prototype_array_suffixes()` in
`src/dcc/dcc_func.c` when the parser encounters the second, run-time array
dimension. dcc already accepts an outer run-time VLA dimension, but currently
rejects an inner run-time dimension because its parameter metadata does not
carry a run-time row stride.

## Oracle result

Clang accepts the source with the same warning settings used by the suite and
executes it successfully:

```sh
clang -std=c99 -Wall -Wextra -pedantic -fsigned-char examples/c9912.c \
    -o /tmp/c9912 && /tmp/c9912
```

Output:

```text
c9912 vlamatrix=21
```

This confirms that the source is valid C99 and that the failure is a dcc
front-end capability gap rather than a source or runtime error.

## Compiler-side fix

The rejection in `skip_prototype_array_suffixes()` should be replaced with
metadata for a pointer to a variable-sized row. Conceptually, the current
logic is:

```c
if (ndims > 0)
    error_here("variable inner dimensions in variable-length arrays are not supported; use malloc and an explicit pointer");
skip_array_dim_to_close();
n = 0;
```

The compiler should instead parse and retain the run-time inner bound:

```c
if (array_dim_has_runtime_identifier()) {
    skip_array_dim_to_close();

    if (ndims == 0) {
        /* The outer bound controls the number of pointer slots. */
        n = 0;
    } else {
        /* Preserve the run-time row width for grid[r][c]. */
        g_ptr_array_has_runtime_stride = 1;
        g_ptr_array_stride_expr = saved_array_dim_expression;
        g_ptr_array_elem_size = type_size(orig_type);
        n = 0;
    }
}
```

The exact representation can follow dcc's existing VLA symbol metadata, but
the code-generation path must use the saved row width when lowering
`grid[r][c]`:

```c
row_address = grid + r * runtime_cols * sizeof(int);
element_address = row_address + c * sizeof(int);
total += *element_address;
```

The implementation must also evaluate the bound expression according to C99
parameter rules, preserve its value for every access in the function body,
and keep the existing 16-bit pointer and `int` target model. It must not
silently treat the inner dimension as a constant or as a pointer to a single
`int`, because either choice would generate incorrect row addresses.

## Expected outcome after the fix

`c9912.c` should compile, assemble, link, and run under ntvcm. The dcc result
must match the Clang oracle:

```text
c9912 vlamatrix=21
```

The test should remain unchanged as a regression test. A valid C99 VLA
parameter must not be rewritten to an explicit pointer or hidden behind a
malloc workaround merely to accommodate the compiler.
