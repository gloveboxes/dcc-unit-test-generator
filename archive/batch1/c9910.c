#include <stdio.h>

struct Pixel { unsigned red:5; unsigned green:6; unsigned blue:5; };
int main(void)
{
    struct Pixel p = {31, 12, 7};
    unsigned packed = (p.red << 11) | (p.green << 5) | p.blue;
    printf("c9910 rgb565=%X\n", packed);
    return 0;
}
