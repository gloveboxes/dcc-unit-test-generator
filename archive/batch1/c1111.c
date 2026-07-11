#include <stdio.h>

struct Slot { int used; int value; };
int main(void)
{
    struct Slot pool[4] = {{0, 0}, {1, 8}, {0, 0}, {1, 3}};
    int i, free_count = 0, total = 0;
    for (i = 0; i < 4; ++i) { if (!pool[i].used) ++free_count; total += pool[i].value; }
    printf("c1111 pool=free%d/value%d\n", free_count, total);
    return 0;
}
