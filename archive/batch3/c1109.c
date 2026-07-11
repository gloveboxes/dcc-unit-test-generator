#include <stdio.h>
struct Rect{struct{int x;int y;};struct{int width;int height;};};
static int area(struct Rect r){return r.width*r.height;}
int main(void){struct Rect r={.x=3,.y=4,.width=7,.height=5};printf("c1109 rect=%d,%d/%d\n",r.x,r.y,area(r));return 0;}
