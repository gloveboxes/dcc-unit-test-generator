#include <stdio.h>

static int luhn(const char *s)
{
    int sum = 0, alternate = 0, digit;
    int i;
    for (i = 0; s[i] != '\0'; ++i) { }
    while (i-- > 0) {
        digit = s[i] - '0';
        if (alternate && (digit *= 2) > 9) digit -= 9;
        sum += digit; alternate = !alternate;
    }
    return sum % 10 == 0;
}
int main(void)
{
    printf("c8904 valid=%d\n", luhn("79927398713"));
    return 0;
}
