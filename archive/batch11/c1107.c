#include <stdio.h>
#include <stdint.h>
/* little-endian overlay — valid on Z80 and the test host */
union DWord { uint32_t dword; struct { uint16_t lo; uint16_t hi; }; };
static uint32_t byteswap32(uint32_t v) {
    union DWord u = {.dword = v};
    uint16_t t = u.lo;
    u.lo = (uint16_t)((u.hi >> 8) | (u.hi << 8));
    u.hi = (uint16_t)((t >> 8) | (t << 8));
    return u.dword;
}
int main(void) {
    uint32_t r = byteswap32(0x12345678UL);
    printf("c1107 bswap=%08lx\n", (unsigned long)r);
    return r != 0x78563412UL;
}
