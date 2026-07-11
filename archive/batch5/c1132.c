#include <stdio.h>
struct DateTime{struct{int year;int month;int day;};struct{int hour;int minute;};};
int main(void){struct DateTime d={.year=2026,.month=7,.day=10,.hour=12,.minute=30};printf("c1132 datetime=%d/%d\n",d.year,d.hour);return 0;}
