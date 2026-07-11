#include <stdio.h>

static inline int clamp(int value, int low, int high)
{
    return value < low ? low : (value > high ? high : value);
}
int main(void)
{
    int values[5] = {-4, 2, 19, 8, 31}, i, total = 0;
    for (i = 0; i < 5; ++i) total += clamp(values[i], 0, 10);
    printf("c9907 clamped=%d\n", total);
    return 0;
}
