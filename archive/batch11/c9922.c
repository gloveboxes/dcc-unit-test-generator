#include <stdio.h>
#include <stdint.h>
static void conv1d(int n, const int32_t * restrict signal,
                   int k, const int32_t * restrict kernel,
                   int32_t * restrict out) {
    for (int i = 0; i < n - k + 1; i++) {
        int32_t s = 0;
        for (int j = 0; j < k; j++) s += signal[i + j] * kernel[j];
        out[i] = s;
    }
}
int main(void) {
    int32_t sig[6] = {1, 2, 3, 4, 5, 6};
    int32_t ker[3] = {1, 0, -1};
    int32_t out[4];
    conv1d(6, sig, 3, ker, out);
    printf("c9922 conv=%ld,%ld\n", (long)out[0], (long)out[3]);
    return !(out[0] == -2L && out[3] == -2L);
}
