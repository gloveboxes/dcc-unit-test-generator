#include <stdio.h>

static long modular_power(long base, int exponent, long modulus)
{
    long result = 1L;
    base %= modulus;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % modulus;
        base = (base * base) % modulus; exponent >>= 1;
    }
    return result;
}

int main(void)
{
    long value = modular_power(7L, 13, 97L);
    printf("c8928 modpow=%ld\n", value);
    return value != 38L;
}
