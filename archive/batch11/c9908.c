#include <stdio.h>
#include <stdint.h>
struct RGB565 { uint16_t r:5, g:6, b:5; };
int main(void) {
    struct RGB565 px = {.r = 31, .g = 20, .b = 15};
    uint16_t packed = (uint16_t)((px.r << 11) | (px.g << 5) | px.b);
    printf("c9908 rgb=%04x,%u\n", (unsigned)packed, (unsigned)px.g);
    return !((packed & 0x001FU) == 15U && px.g == 20U);
}
