#include <stdio.h>

enum ConstraintKind { FIXED,INSET,FRACTION };struct Constraint { enum ConstraintKind kind;union { int pixels;struct { int before,after; };struct { int numerator,denominator; }; }; };
static int resolve(const struct Constraint *c,int available){if(c->kind==FIXED)return c->pixels;if(c->kind==INSET)return available-c->before-c->after;return available*c->numerator/c->denominator;}
int main(void){struct Constraint a={.kind=FIXED,.pixels=18},b={.kind=INSET,.before=4,.after=6},c={.kind=FRACTION,.numerator=3,.denominator=5};int x=resolve(&a,80),y=resolve(&b,80),z=resolve(&c,80);printf("c1132 layout=%d,%d,%d\n",x,y,z);return !(x==18&&y==70&&z==48);}
