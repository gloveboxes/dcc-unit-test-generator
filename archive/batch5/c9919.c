#include <stdio.h>
struct Rect{int x;int y;int w;int h;};
static int area(struct Rect r){return r.w*r.h;}
int main(void){struct Rect r={.x=2,.y=3,.w=7,.h=5};printf("c9919 rect=%d,%d\n",r.x,area(r));return 0;}
