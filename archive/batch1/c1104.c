#include <stdio.h>

union Color { unsigned value; struct { unsigned char red, green, blue, alpha; }; };
int main(void)
{
    union Color c;
    c.red = 10; c.green = 20; c.blue = 30; c.alpha = 255;
    printf("c1104 color=%u,%u,%u,%u\n", c.red, c.green, c.blue, c.alpha);
    return 0;
}
