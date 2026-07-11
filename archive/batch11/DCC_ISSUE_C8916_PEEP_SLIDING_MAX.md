# Fixed dcc regression: dccpeep miscompiled sliding-window maximum with deque

**Status:** Fixed and regression-verified 2026-07-10.

## Fix verification

The original source in `c8916.c` now compiles, runs, and passes under the
default `dcc-peep=true` build. No source workaround was applied.

```sh
./validate-examples.sh all
```

The complete 100-test suite passed every applicable strict Clang mode and all
dcc/ntvcm builds. `c8916` now prints `c8916 slmax=6,3,5,7` and exits 0.

## Summary

dcc's peephole optimizer (`dccpeep`) produces incorrect code for a
sliding-window maximum algorithm that maintains a monotone deque of
array indices.  The correct C89-valid program produces wrong output
under `dccpeep` on every variant tested; disabling peephole
optimisation (`dcc-peep=false`) produces the correct result every time.
dcc's front-end and the M80/L80 linker accept and assemble the program
without errors.

The test source is `c8916.c`, which is preserved unchanged as a
regression test.

---

## Complete reproduction — `c8916.c`

```c
#include <stdio.h>
#define W 8

static int sliding_max(const int a[], int n, int k, int out[])
{
    int dq[W], head = 0, tail = 0, count = 0, i;
    for (i = 0; i < n; ++i) {
        int limit = i - k + 1;
        while (head < tail && dq[head] < limit)  ++head;
        while (head < tail && a[dq[tail-1]] <= a[i]) --tail;
        dq[tail++] = i;
        if (i >= k - 1) out[count++] = a[dq[head]];
    }
    return count;
}

int main(void)
{
    int a[8] = {1, 3, -1, -3, 5, 3, 6, 7}, out[6];
    int n = sliding_max(a, 8, 3, out);
    printf("c8916 slmax=%d,%d,%d,%d\n", n, out[0], out[2], out[5]);
    return !(n == 6 && out[0] == 3 && out[2] == 5 && out[5] == 7);
}
```

For the input array `{1,3,-1,-3,5,3,6,7}` with window `k=3` the
sliding maxima are `{3, 3, 5, 5, 6, 7}` (6 values).

---

## Oracle

```sh
clang -std=c89 -Wall -Wextra -pedantic -fsigned-char \
    examples/c8916.c -o /tmp/c8916
/tmp/c8916
```

Expected output and exit status:

```
c8916 slmax=6,3,5,7
exit status 0
```

The source also passes `-std=c99` and `-std=c11`.

---

## dcc reproduction

### With peephole optimisation (default — fails)

```sh
dccmake dcc-input=examples/c8916.c dcc-output=C8916 \
    dcc-build-dir=bc8916
ntvcm bc8916/C8916.COM
```

Actual output and exit status:

```
c8916 slmax=6,3,-1,3
exit status 1
```

`out[2]` is `-1` (the raw input value) instead of `5`; `out[5]` is `3`
instead of `7`.  The build completes with no compiler, assembler, or
linker errors.

### Without peephole optimisation — passes

```sh
dccmake dcc-input=examples/c8916.c dcc-output=C8916 \
    dcc-build-dir=/tmp/bnpc8916 dcc-peep=false
ntvcm /tmp/bnpc8916/C8916.COM
```

Output and exit status:

```
c8916 slmax=6,3,5,7
exit status 0
```

---

## Isolation matrix

| Variant | peep=true | peep=false |
|---|---|---|
| Original: automatic `int dq[W]`, `int limit = i-k+1` in for-init | `6,3,-1,3` **FAIL** | `6,3,5,7` PASS |
| Static `static int dq[W]` (same loop body) | `6,3,-1,3` **FAIL** | `6,3,5,7` PASS |
| Inline eviction: `dq[head] <= i-k` instead of `< limit` | `6,3,-1,3` **FAIL** | `6,3,5,7` PASS |

All three variants fail with the same wrong values under `dccpeep` and
pass without it.  The bug is in `dccpeep`, not in dcc's initial code
generation or the storage class of the deque.

---

## Workaround

Pass `dcc-peep=false` to `dccmake` to bypass the peephole optimizer:

```sh
dccmake dcc-input=examples/c8916.c dcc-output=C8916 \
    dcc-build-dir=bc8916 dcc-peep=false
```

This workaround is documented for isolation purposes only.  It has
**not** been applied to `c8916.c`; the original valid source is
intentionally preserved as a regression test.

---

## Expected dcc behaviour

After the defect is fixed in `dccpeep`, both of the following should
produce:

```
c8916 slmax=6,3,5,7
exit status 0
```

```sh
# default (peep=true)
dccmake dcc-input=examples/c8916.c dcc-output=C8916 dcc-build-dir=bc8916
ntvcm bc8916/C8916.COM

# explicit
dccmake dcc-input=examples/c8916.c dcc-output=C8916 \
    dcc-build-dir=bc8916 dcc-peep=true
ntvcm bc8916/C8916.COM
```
