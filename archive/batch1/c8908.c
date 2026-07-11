#include <stdio.h>

int main(void)
{
    int a[8] = {-2, 3, -1, 4, -5, 6, -2, 3}, best = a[0], here = a[0], i;
    for (i = 1; i < 8; ++i) {
        here = here + a[i] > a[i] ? here + a[i] : a[i];
        if (here > best) best = here;
    }
    printf("c8908 maximum=%d\n", best);
    return 0;
}
