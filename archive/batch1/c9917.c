#include <stdio.h>

static int rotate(int value, int shift)
{
    unsigned bits = (unsigned)value;
    return (int)((bits << shift) | (bits >> (16 - shift)));
}
int main(void)
{
    printf("c9917 rotate=%X\n", (unsigned)rotate(0x1234, 5));
    return 0;
}
