#include <stdio.h>

int main(void)
{
    int n = 45, a = 0, b = 1, c, i;
    for (i = 0; i < n; ++i) { c = a + b; a = b; b = c; }
    printf("c8914 fib=%d\n", a);
    return 0;
}
