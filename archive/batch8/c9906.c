#include <stdio.h>
static void axpy(int count, int scale, const int * restrict x, int * restrict y) {
    for (int i = 0; i < count; ++i) y[i] += scale * x[i];
}
int main(void) {
    int x[3] = {1,2,3}, y[3] = {10,10,10}; axpy(3, 4, x, y);
    printf("c9906 axpy=%d,%d\n", y[0], y[2]); return !(y[0] == 14 && y[2] == 22);
}
