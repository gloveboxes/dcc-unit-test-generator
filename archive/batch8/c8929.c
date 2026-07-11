#include <stdio.h>

static int factorize(int value, int factors[], int capacity)
{
    int divisor = 2; int count = 0;
    while (value > 1) {
        while (value % divisor == 0) {
            if (count == capacity) return -1;
            factors[count++] = divisor; value /= divisor;
        }
        ++divisor;
    }
    return count;
}

int main(void)
{
    int factors[8]; int count = factorize(756, factors, 8);
    printf("c8929 factors=%d,%d,%d\n", count, factors[0], factors[count-1]);
    return !(count == 6 && factors[0] == 2 && factors[count-1] == 7);
}
