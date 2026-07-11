#include <stdio.h>

int main(void)
{
    int n = 6, a[6] = {1, 1, 2, 3, 5, 8}, i, j, x, ok = 1;
    for (i = 0; i < n; ++i) for (j = i + 1; j < n; ++j)
        if (a[i] == a[j]) ok = 0;
    x = a[0] + a[n - 1];
    printf("c8911 unique=%d edge=%d\n", ok, x);
    return 0;
}
