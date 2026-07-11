#include <stdio.h>

struct Point { struct { int x; int y; }; };
int main(void)
{
    struct Point p = {{7, -3}};
    printf("c1101 anonymous=%d,%d\n", p.x, p.y);
    return 0;
}
