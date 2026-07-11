#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool prime[25];
    int i, j, count = 0;
    for (i = 0; i < 25; ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    for (i = 2; i * i < 25; ++i) if (prime[i])
        for (j = i * i; j < 25; j += i) prime[j] = false;
    for (i = 0; i < 25; ++i) count += prime[i] ? 1 : 0;
    printf("c9905 boolprimes=%d\n", count);
    return 0;
}
