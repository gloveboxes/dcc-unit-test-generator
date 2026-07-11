#include <stdio.h>
struct Optional { int present; union { int value; }; };
static int value_or(const struct Optional *o,int fallback){return o->present?o->value:fallback;}
int main(void){struct Optional a={1,{9}},b={0,{0}};int x=value_or(&a,5),y=value_or(&b,5);printf("c1115 optional=%d,%d\n",x,y);return !(x==9&&y==5);}
