#include <stdio.h>
#include <stdint.h>
static inline uint32_t pack_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a;
}
static inline uint8_t unpack_g(uint32_t rgba) { return (uint8_t)((rgba >> 16) & 0xFFU); }
int main(void) {
    uint32_t px = pack_rgba(0x10U, 0x20U, 0x30U, 0xFFU);
    printf("c9920 rgba=%08lx,%u\n", (unsigned long)px, (unsigned)unpack_g(px));
    return !(px == 0x102030FFUL && unpack_g(px) == 0x20U);
}
