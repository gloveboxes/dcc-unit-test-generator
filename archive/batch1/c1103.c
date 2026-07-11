#include <stdio.h>

struct Frame { struct { unsigned version:4; unsigned type:4; }; union { unsigned length; struct { unsigned low; }; }; };
int main(void)
{
    struct Frame f = {{2, 9}, {37}};
    printf("c1103 frame=%u/%u\n", f.version + f.type, f.length);
    return 0;
}
