#include <stdio.h>

static int derivative(const int *coef, int degree, int x, long *value)
{
    int i; long y;
    if (degree < 1) { *value = 0L; return 0; }
    y = (long)degree * coef[degree];
    for (i = degree - 1; i >= 1; --i) y = y * x + (long)i * coef[i];
    *value = y; return degree - 1;
}

int main(void)
{
    int coef[5] = {7,-3,5,0,2}; int degree; long at2, atminus1;
    degree = derivative(coef,4,2,&at2); derivative(coef,4,-1,&atminus1);
    printf("c8910 derivative=%d,%ld,%ld\n", degree, at2, atminus1);
    return !(degree == 3 && at2 == 81L && atminus1 == -21L);
}
