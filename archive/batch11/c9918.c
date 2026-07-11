#include <stdio.h>
#include <stdint.h>
static void reverse_restrict(int n, const int32_t * restrict src, int32_t * restrict dst) {
    for (int i = 0; i < n; i++) dst[n - 1 - i] = src[i];
}
int main(void) {
    int32_t src[6] = {10, 20, 30, 40, 50, 60};
    int32_t dst[6];
    reverse_restrict(6, src, dst);
    printf("c9918 rev=%ld,%ld\n", (long)dst[0], (long)dst[5]);
    return !(dst[0] == 60L && dst[5] == 10L);
}
