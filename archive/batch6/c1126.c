#include <stdio.h>
struct Coord{union{struct{int x;int y;};int axis[2];};};
static int manhattan(struct Coord a,struct Coord b){int dx=a.x-b.x,dy=a.y-b.y;return (dx<0?-dx:dx)+(dy<0?-dy:dy);}
int main(void){struct Coord a={.x=3,.y=4},b={.x=8,.y=1};printf("c1126 coord=%d\n",manhattan(a,b));return 0;}
