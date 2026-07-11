#include <stdio.h>
struct Date{unsigned year:7;unsigned month:4;unsigned day:5;};
static int valid(struct Date d){return d.month>=1&&d.month<=12&&d.day>=1&&d.day<=31;}
int main(void){struct Date d={26,7,14};printf("c1121 date=%d\n",valid(d));return 0;}
