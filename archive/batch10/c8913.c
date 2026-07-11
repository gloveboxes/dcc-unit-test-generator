#include <stdio.h>

static int leap(int y) { return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); }
static int ordinal(int y, int m, int d)
{
    static const int before[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
    return before[m - 1] + d + (m > 2 && leap(y));
}
static int weekday(int y, int m, int d)
{
    int total, yy;
    total = 0;
    for (yy = 2000; yy < y; ++yy) total += leap(yy) ? 366 : 365;
    total += ordinal(y,m,d) - 1;
    return (total + 6) % 7;
}

int main(void)
{
    int a, b;
    a = ordinal(2024,12,31); b = weekday(2026,7,10);
    printf("c8913 calendar=%d,%d\n", a, b);
    return !(a == 366 && b == 5);
}
