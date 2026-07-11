#include <stdio.h>

static int roman_value(char ch)
{
    switch (ch) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    default: return 0;
    }
}

static int parse_roman(const char *text)
{
    int total = 0;
    int current;
    int next;
    while (*text != '\0') {
        current = roman_value(*text);
        next = roman_value(text[1]);
        total += current < next ? -current : current;
        ++text;
    }
    return total;
}

int main(void)
{
    int value = parse_roman("XLIV");
    printf("c8908 roman=%d\n", value);
    return value != 44;
}
