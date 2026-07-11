#include <stdio.h>
struct Date{int yr;int mo;int dy;};
static int is_leap(struct Date d){return d.yr%4==0&&(d.yr%100!=0||d.yr%400==0);}
int main(void){printf("c9933 leap=%d,%d\n",is_leap((struct Date){.yr=2024}),is_leap((struct Date){.yr=2100}));return 0;}
