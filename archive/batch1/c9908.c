#include <stdarg.h>
#include <stdio.h>

static int sum(int count, ...)
{
    va_list args;
    int i, total = 0;
    va_start(args, count);
    for (i = 0; i < count; ++i) total += va_arg(args, int);
    va_end(args);
    return total;
}
int main(void)
{
    printf("c9908 variadic=%d\n", sum(5, 3, 1, 4, 1, 5));
    return 0;
}
