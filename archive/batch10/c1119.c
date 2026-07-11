#include <stdio.h>

struct Capsule { union { struct { int ax,ay,bx,by; };struct { int start[2],end[2]; }; };int radius; };
static int bound(const struct Capsule *c){int dx=c->bx-c->ax,dy=c->by-c->ay;if(dx<0)dx=-dx;if(dy<0)dy=-dy;return dx+dy+4*c->radius;}
int main(void){struct Capsule c={.ax=2,.ay=7,.bx=11,.by=3,.radius=2};int value=bound(&c);printf("c1119 capsule=%d,%d,%d\n",value,c.start[1],c.end[0]);return !(value==21&&c.start[1]==7&&c.end[0]==11);}
