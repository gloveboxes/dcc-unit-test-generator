#include <stdio.h>

struct Fixed { union { long raw; struct { int whole; unsigned fraction; }; }; };
int main(void)
{
    struct Fixed value;
    value.whole = 12; value.fraction = 500;
    printf("c1110 fixedpoint=%d.%u\n", value.whole, value.fraction);
    return 0;
}
