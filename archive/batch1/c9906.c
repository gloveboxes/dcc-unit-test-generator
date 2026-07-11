#include <stdio.h>

int main(void)
{
    int n = 6, a[6], i, window = 0, best = -1;
    for (i = 0; i < n; ++i) a[i] = i + 2;
    for (i = 0; i < n; ++i) { window += a[i]; if (i >= 2) window -= a[i - 2]; if (window > best) best = window; }
    printf("c9906 vla=%d\n", best);
    return 0;
}
