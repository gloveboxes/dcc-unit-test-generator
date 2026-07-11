#include <stdio.h>

struct Date { union { unsigned value; struct { unsigned day:5; unsigned month:4; unsigned year:7; }; }; };
int main(void)
{
    struct Date date = {.day = 17, .month = 6, .year = 42};
    printf("c1115 date=%u/%u/%u\n", date.day, date.month, date.year);
    return 0;
}
