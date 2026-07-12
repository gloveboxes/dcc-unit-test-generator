#include <stdio.h>

static unsigned short crc16(const unsigned char *s)
{
    unsigned short crc = 0xffff;
    int i;
    while (*s != 0) {
        crc ^= *s++;
        for (i = 0; i < 8; ++i)
            crc = (crc & 1) ? (crc >> 1) ^ 0xa001 : crc >> 1;
    }
    return crc;
}
int main(void)
{
    printf("c8903 crc=%04X\n", (unsigned)crc16((const unsigned char *)"dcc"));
    return 0;
}
