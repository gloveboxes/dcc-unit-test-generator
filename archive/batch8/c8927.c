#include <stdio.h>

#define LIMIT 50
static int count_primes(void)
{
    unsigned char composite[LIMIT + 1]; int i; int multiple; int count = 0;
    for (i = 0; i <= LIMIT; ++i) composite[i] = 0;
    for (i = 2; i * i <= LIMIT; ++i)
        if (!composite[i])
            for (multiple = i * i; multiple <= LIMIT; multiple += i) composite[multiple] = 1;
    for (i = 2; i <= LIMIT; ++i) if (!composite[i]) ++count;
    return count;
}

int main(void)
{
    int count = count_primes();
    printf("c8927 primes=%d\n", count);
    return count != 15;
}
