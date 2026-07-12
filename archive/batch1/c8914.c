#include <stdio.h>

int main(void)
{
    int n = 45, i;
    unsigned short a = 0, b = 1, c;
    for (i = 0; i < n; ++i) { c = a + b; a = b; b = c; }
    printf("c8914 fib=%u\n", (unsigned)a);
    return 0;
}
