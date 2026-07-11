#include <stdio.h>

static int day_of_year(int year, int month, int day)
{
    static const int before[] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
    int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    return before[month] + day + (leap && month > 2);
}

int main(void)
{
    int leap_day = day_of_year(2024, 3, 1);
    int common_day = day_of_year(2025, 3, 1);
    printf("c8916 ordinal=%d,%d\n", leap_day, common_day);
    return !(leap_day == 61 && common_day == 60);
}
