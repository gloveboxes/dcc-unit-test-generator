#include <stdio.h>
#include <stdint.h>

static uint16_t rotate(uint16_t value, int shift)
{
    uint16_t bits = value;
    return (uint16_t)((bits << shift) | (bits >> (16 - shift)));
}
int main(void)
{
    printf("c9917 rotate=%X\n", (unsigned)rotate(0x1234, 5));
    return 0;
}
