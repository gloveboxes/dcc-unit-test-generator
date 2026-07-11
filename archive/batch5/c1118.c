#include <stdio.h>
struct Date{union{unsigned value;struct{unsigned day:5;unsigned month:4;unsigned year:7;};};};
int main(void){struct Date d={.day=14,.month=7,.year=26};printf("c1118 date=%u/%u/%u\n",d.day,d.month,d.year);return 0;}
