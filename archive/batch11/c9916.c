#include <stdio.h>
#include <stdint.h>
struct Register16 { uint8_t lo; uint8_t hi; };
static const struct Register16 table[4] = {
    [0] = {.lo = 0x34, .hi = 0x12},
    [1] = {.lo = 0xCD, .hi = 0xAB},
    [2] = {.lo = 0x78, .hi = 0x56},
    [3] = {.lo = 0xF0, .hi = 0x9E}
};
int main(void) {
    int total = 0;
    for (int i = 0; i < 4; i++) total += table[i].hi;
    printf("c9916 regtbl=%d,%02x\n", total, (unsigned)table[2].lo);
    return !(total == 0x12 + 0xAB + 0x56 + 0x9E && table[2].lo == 0x78);
}
