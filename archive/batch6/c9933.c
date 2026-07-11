#include <stdio.h>
struct Date{int year;int month;int day;};
static int serial(struct Date d){return d.year*372+d.month*31+d.day;}
int main(void){struct Date a={.year=2026,.month=7,.day=10},b={.year=2026,.month=7,.day=25};printf("c9933 dates=%d\n",serial(b)-serial(a));return 0;}
