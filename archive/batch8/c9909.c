#include <stdio.h>
#include <stdarg.h>
static long maximum(int count, ...) {
    va_list args; long best, value; va_start(args, count); best = va_arg(args, long);
    for (int i = 1; i < count; ++i) { value = va_arg(args, long); if (value > best) best = value; }
    va_end(args); return best;
}
int main(void) { long actual = maximum(4, -4L, 1200L, 32L, 99L); printf("c9909 varmax=%ld\n", actual); return actual != 1200L; }
