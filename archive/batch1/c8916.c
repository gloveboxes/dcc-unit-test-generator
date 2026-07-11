#include <stdio.h>

int main(void)
{
    int value = 173, digits[8], count = 0, i;
    do { digits[count++] = value % 2; value /= 2; } while (value != 0);
    printf("c8916 binary=");
    for (i = count - 1; i >= 0; --i) putchar('0' + digits[i]);
    putchar('\n');
    return 0;
}
