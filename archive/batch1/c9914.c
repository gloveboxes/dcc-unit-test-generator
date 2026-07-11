#include <stdio.h>

struct Point { int x; int y; };
static struct Point scale(struct Point p, int factor)
{
    return (struct Point){p.x * factor, p.y * factor};
}
int main(void)
{
    struct Point p = scale((struct Point){3, -2}, 4);
    printf("c9914 point=%d,%d\n", p.x, p.y);
    return 0;
}
