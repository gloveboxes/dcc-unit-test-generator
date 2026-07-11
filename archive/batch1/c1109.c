#include <stdio.h>

struct Address { union { unsigned char octet[4]; struct { unsigned char a, b, c, d; }; }; };
int main(void)
{
    struct Address address = {.a = 192, .b = 168, .c = 1, .d = 20};
    printf("c1109 ipv4=%u.%u.%u.%u\n", address.a, address.b, address.c, address.d);
    return 0;
}
