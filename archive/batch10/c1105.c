#include <stdio.h>

struct Retry { union { struct { int base,limit,multiplier; }; int values[3]; }; };
static int delay(const struct Retry *p,int attempt){long d=p->base;while(attempt-->0&&d<p->limit)d*=p->multiplier;if(d>p->limit)d=p->limit;return (int)d;}
int main(void){struct Retry p={.base=3,.limit=40,.multiplier=2};int a=delay(&p,2),b=delay(&p,6);printf("c1105 retry=%d,%d,%d\n",a,b,p.values[2]);return !(a==12&&b==40&&p.values[2]==2);}
