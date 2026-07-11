#include <stdio.h>
struct Range { union { struct { int minimum,maximum; }; int bound[2]; }; };
static int span(const struct Range *r){return r->maximum-r->minimum;}
int main(void){struct Range r={{.minimum=-5,.maximum=12}};int actual=span(&r);printf("c1126 range=%d,%d\n",actual,r.bound[0]);return !(actual==17&&r.minimum==-5);}
