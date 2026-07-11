#include <stdio.h>
struct Date{int year,month,day;};
static int leap(int y){return y%4==0&&(y%100!=0||y%400==0);}
static void next_day(struct Date *d){static const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};int limit=days[d->month]+(d->month==2&&leap(d->year));if(++d->day>limit){d->day=1;if(++d->month>12){d->month=1;++d->year;}}}
int main(void){struct Date d={2024,2,28};next_day(&d);next_day(&d);printf("c8928 date=%d-%d-%d\n",d.year,d.month,d.day);return !(d.year==2024&&d.month==3&&d.day==1);}
