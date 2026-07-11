#include <stdio.h>

static int roman(char c)
{
    if (c == 'I') return 1; if (c == 'V') return 5; if (c == 'X') return 10;
    if (c == 'L') return 50; if (c == 'C') return 100; return 0;
}
int main(void)
{
    const char *s = "MCMXLIV";
    int total = 0, i, current, next;
    for (i = 0; s[i] != '\0'; ++i) {
        current = roman(s[i]); next = roman(s[i + 1]);
        total += current < next ? -current : current;
    }
    printf("c8910 roman=%d\n", total);
    return 0;
}
