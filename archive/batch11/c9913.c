#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
static void saxpy(int n, int32_t a, const int32_t * restrict x, int32_t * restrict y) {
    for (int i = 0; i < n; i++) y[i] += a * x[i];
}
int main(void) {
    int32_t x[5] = {1, 2, 3, 4, 5};
    int32_t y[5] = {10, 20, 30, 40, 50};
    saxpy(5, 3L, x, y);
    printf("c9913 saxpy=%ld,%ld\n", (long)y[0], (long)y[4]);
    return !(y[0] == 13L && y[4] == 65L);
}
