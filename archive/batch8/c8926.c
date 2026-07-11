#include <stdio.h>

static int josephus(int people, int step)
{
    int survivor = 0; int size;
    for (size = 2; size <= people; ++size) survivor = (survivor + step) % size;
    return survivor + 1;
}

int main(void)
{
    int survivor = josephus(10, 3);
    printf("c8926 josephus=%d\n", survivor);
    return survivor != 4;
}
