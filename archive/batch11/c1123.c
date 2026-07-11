#include <stdio.h>
#include <stdint.h>
/* little-endian byte overlay — valid on Z80 and the test host */
union Float32 {
    float f;
    uint32_t bits;
    struct { unsigned mantissa_lo:16; unsigned mantissa_hi:7; unsigned exponent:8; unsigned sign:1; };
};
int main(void) {
    union Float32 v = {.f = -2.0f};
    printf("c1123 float=%u,%u\n", (unsigned)v.sign, (unsigned)v.exponent);
    return !(v.sign == 1 && v.exponent == 128);
}
