#include <stdio.h>
struct Bounds{struct{int minimum;int maximum;};};
static int span(struct Bounds b){return b.maximum-b.minimum;}
int main(void){struct Bounds b={.minimum=-3,.maximum=12};printf("c1121 bounds=%d\n",span(b));return 0;}
