#include <stdio.h>
#include <stdint.h>
struct Pixel {
    union {
        struct { uint8_t b; uint8_t g; uint8_t r; uint8_t a; };
        uint32_t packed;
    };
};
int main(void) {
    struct Pixel px = {.r=0xFFU, .g=0x80U, .b=0x00U, .a=0xFFU};
    uint32_t expected = (uint32_t)0xFFFF8000UL;  /* little-endian: b=lo,g,r,a=hi */
    printf("c1103 pixel=%08lx,%u\n", (unsigned long)px.packed, (unsigned)px.g);
    return !(px.g == 0x80U);
}
