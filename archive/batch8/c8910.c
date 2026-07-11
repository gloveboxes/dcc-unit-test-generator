#include <stdio.h>

static long rounded_average(const long values[], int count)
{
    long total = 0L;
    int i;
    for (i = 0; i < count; ++i) total += values[i];
    if (total >= 0) return (total + count / 2) / count;
    return (total - count / 2) / count;
}

int main(void)
{
    static const long samples[] = {123L, 127L, 130L, 124L};
    long average = rounded_average(samples, 4);
    printf("c8910 average=%ld\n", average);
    return average != 126L;
}
