#include <stdio.h>
#include <stdint.h>
static inline int32_t dot_restrict(int n, const int32_t * restrict a, const int32_t * restrict b) {
    int32_t s = 0;
    for (int i = 0; i < n; i++) s += a[i] * b[i];
    return s;
}
int main(void) {
    int32_t a[5] = {1, -2, 3, 4, -1};
    int32_t b[5] = {2,  3, 1, 0,  5};
    int32_t d = dot_restrict(5, a, b);
    printf("c9907 dot=%ld\n", (long)d);
    return d != -6L;
}
