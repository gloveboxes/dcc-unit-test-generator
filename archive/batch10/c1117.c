#include <stdio.h>
#include <stdbool.h>

enum OptionKind { ABSENT,NUMBER,PAIR };struct Option { enum OptionKind kind;union { int number;struct { int first,second; }; }; };
static int resolve(const struct Option *o,int fallback){if(o->kind==ABSENT)return fallback;if(o->kind==NUMBER)return o->number;return o->first+o->second;}
int main(void){struct Option a={.kind=ABSENT},b={.kind=NUMBER,.number=17},c={.kind=PAIR,.first=8,.second=13};int sum=resolve(&a,4)+resolve(&b,0)+resolve(&c,0);printf("c1117 options=%d,%d\n",sum,c.second);return !(sum==42&&c.second==13);}
