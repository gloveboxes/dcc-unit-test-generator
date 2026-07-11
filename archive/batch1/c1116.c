#include <stdio.h>

struct Rectangle { struct { int left; int top; }; struct { int right; int bottom; }; };
int main(void)
{
    struct Rectangle box = {{2, 3}, {11, 9}};
    printf("c1116 area=%d\n", (box.right - box.left) * (box.bottom - box.top));
    return 0;
}
