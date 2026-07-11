#include <stdio.h>

int main(void)
{
    int n = 30, prime[31], i, j, count = 0, sum = 0;
    for (i = 0; i <= n; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (i = 2; i * i <= n; ++i) if (prime[i])
        for (j = i * i; j <= n; j += i) prime[j] = 0;
    for (i = 2; i <= n; ++i) if (prime[i]) { ++count; sum += i; }
    printf("c8907 primes=%d sum=%d\n", count, sum);
    return 0;
}
