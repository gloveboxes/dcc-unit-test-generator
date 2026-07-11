#include <stdio.h>

static int luhn_valid(const char *digits)
{
    int length = 0;
    int sum = 0;
    int value;
    int i;
    while (digits[length] != '\0') ++length;
    for (i = 0; i < length; ++i) {
        value = digits[i] - '0';
        if (((length - i) % 2) == 0) {
            value *= 2;
            if (value > 9) value -= 9;
        }
        sum += value;
    }
    return sum % 10 == 0;
}

int main(void)
{
    int valid = luhn_valid("79927398713");
    int invalid = luhn_valid("79927398714");
    printf("c8906 luhn=%d,%d\n", valid, invalid);
    return !(valid == 1 && invalid == 0);
}
