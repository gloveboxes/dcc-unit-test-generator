#include <stdio.h>

static int dot(int n, const int * restrict a, const int * restrict b)
{
    int total = 0, i;
    for (i = 0; i < n; ++i) total += a[i] * b[i];
    return total;
}
int main(void)
{
    int a[4] = {2, 3, 5, 7}, b[4] = {11, 13, 17, 19};
    printf("c9904 dot=%d\n", dot(4, a, b));
    return 0;
}
