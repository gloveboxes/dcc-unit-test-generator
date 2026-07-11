#include <stdio.h>
#include <stdint.h>
static int32_t matrix_det2(int32_t a, int32_t b, int32_t c, int32_t d) {
    return a * d - b * c;
}
int main(void) {
    // 2x2 matrices stored row-major
    int32_t m1[4] = {3, 8, 4, 6};  // det = 3*6 - 8*4 = -14
    int32_t m2[4] = {1, 2, 3, 4};  // det = 1*4 - 2*3 = -2
    int32_t d1 = matrix_det2(m1[0], m1[1], m1[2], m1[3]);
    int32_t d2 = matrix_det2(m2[0], m2[1], m2[2], m2[3]);
    printf("c9924 det=%ld,%ld\n", (long)d1, (long)d2);
    return !(d1 == -14L && d2 == -2L);
}
