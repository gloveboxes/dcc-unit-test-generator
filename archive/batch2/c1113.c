#include <stdio.h>
struct Date{union{unsigned value;struct{unsigned day:5;unsigned month:4;unsigned year:7;};};};
int main(void){struct Date d={.day=19,.month=7,.year=44};printf("c1113 date=%u/%u/%u\n",d.day,d.month,d.year);return 0;}
