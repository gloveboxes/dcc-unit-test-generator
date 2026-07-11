#include <stdio.h>

static long charge(long units, long rate, long minimum)
{
    long cents;
    cents = (units * rate + 50L) / 100L;
    return cents < minimum ? minimum : cents;
}

int main(void)
{
    long a, b, total;
    a = charge(375L, 84L, 250L);
    b = charge(120L, 95L, 150L);
    total = a + b;
    printf("c8901 billing=%ld,%ld,%ld\n", a, b, total);
    return !(a == 315L && b == 150L && total == 465L);
}
