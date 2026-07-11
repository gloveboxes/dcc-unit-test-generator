#include <stdio.h>
#include <stdint.h>
/* little-endian overlay — valid on Z80 and the test host */
union Word16 { uint16_t value; struct { uint8_t lo; uint8_t hi; }; };
int main(void) {
    union Word16 w = {.value = 0x1A2BU};
    uint8_t saved_lo = w.lo;
    w.hi ^= 0xFFU;
    printf("c1101 word=%04x,%02x\n", (unsigned)w.value, (unsigned)saved_lo);
    return !(saved_lo == 0x2BU && w.value == 0xE52BU);
}
