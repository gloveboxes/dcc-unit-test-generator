#include <stdio.h>
struct Date{int year;int month;int day;};
static int serial(struct Date d){return d.year*372+d.month*31+d.day;}
int main(void){struct Date dates[2]={{.year=2026,.month=7,.day=10},{.year=2026,.month=12,.day=25}};printf("c9917 dates=%d\n",serial(dates[1])-serial(dates[0]));return 0;}
