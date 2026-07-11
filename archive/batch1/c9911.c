#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int32_t value = (int32_t)30000 * 3;
    uint16_t mask = (uint16_t)0x5A5A;
    printf("c9911 fixed=%ld/%u\n", (long)value, (unsigned)mask);
    return 0;
}
