#include <stdio.h>

static int digit_value(char ch)
{
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    return -1;
}

static long parse_base36(const char *text)
{
    long value = 0L; int digit;
    while (*text) {
        digit = digit_value(*text++);
        if (digit < 0) return -1L;
        value = value * 36L + digit;
    }
    return value;
}

int main(void)
{
    long value = parse_base36("CPM");
    printf("c8930 base36=%ld\n", value);
    return value != 16474L;
}
