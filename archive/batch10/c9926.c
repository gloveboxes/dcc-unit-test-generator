#include <stdio.h>
#include <stdbool.h>

enum Day { MON,TUE,WED,THU,FRI,SAT,SUN,DAYS };struct Shift { int open,close;bool staffed; };
static const struct Shift week[DAYS]={[MON]={8,17,true},[WED]={10,19,true},[FRI]={8,14,true},[SAT]={9,12,true}};
static int hours(void){int total=0;for(int d=0;d<DAYS;++d)if(week[d].staffed)total+=week[d].close-week[d].open;return total;}
int main(void){int total=hours();printf("c9926 schedule=%d,%d\n",total,(int)week[SAT].staffed);return !(total==27&&week[SAT].staffed);}
