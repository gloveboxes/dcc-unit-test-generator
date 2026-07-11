#include <stdio.h>

int main(void)
{
    int values[9] = {1, 4, 2, 4, 3, 1, 4, 2, 0}, bins[5] = {0};
    int n = (int)(sizeof values / sizeof values[0]), i;
    for (i = 0; i < n; ++i) ++bins[values[i]];
    printf("c9903 histogram=%d,%d,%d,%d,%d\n", bins[0], bins[1], bins[2], bins[3], bins[4]);
    return 0;
}
