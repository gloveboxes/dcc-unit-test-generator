#include <stdio.h>

int main(void)
{
    int people = 11, step = 3, survivor = 0, i;
    for (i = 2; i <= people; ++i) survivor = (survivor + step) % i;
    printf("c8917 survivor=%d\n", survivor);
    return 0;
}
