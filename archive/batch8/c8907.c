#include <stdio.h>

static unsigned int fletcher16(const unsigned char data[], int length)
{
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    int i;
    for (i = 0; i < length; ++i) {
        sum1 = (sum1 + data[i]) % 255;
        sum2 = (sum2 + sum1) % 255;
    }
    return (sum2 << 8) | sum1;
}

int main(void)
{
    static const unsigned char data[] = {'C','P','/','M'};
    unsigned int actual = fletcher16(data, 4);
    printf("c8907 fletcher=%04x\n", actual);
    return actual != 0xa910;
}
