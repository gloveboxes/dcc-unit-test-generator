#include <stdio.h>
#include <stdint.h>
struct FixedQ8 {
    union { int16_t raw; struct { uint8_t frac; int8_t whole; }; };
};
static struct FixedQ8 fq8_add(struct FixedQ8 a, struct FixedQ8 b) {
    return (struct FixedQ8){.raw = (int16_t)(a.raw + b.raw)};
}
static int fq8_to_hundredths(struct FixedQ8 v) {
    return (int)v.whole * 100 + ((unsigned)v.frac * 100 / 256);
}
int main(void) {
    struct FixedQ8 a = {.raw = (int16_t)(2 * 256 + 128)};  /* 2.5 */
    struct FixedQ8 b = {.raw = (int16_t)(1 * 256 + 64)};   /* 1.25 */
    struct FixedQ8 r = fq8_add(a, b);
    printf("c1111 fixed=%d\n", fq8_to_hundredths(r));
    return fq8_to_hundredths(r) != 375;
}
