#include <stdio.h>

static int crc16(const unsigned char *s)
{
    int crc = 0xffff, i;
    while (*s != 0) {
        crc ^= *s++;
        for (i = 0; i < 8; ++i)
            crc = (crc & 1) ? (crc >> 1) ^ 0xa001 : crc >> 1;
    }
    return crc;
}
int main(void)
{
    printf("c8903 crc=%04X\n", crc16((const unsigned char *)"dcc"));
    return 0;
}
