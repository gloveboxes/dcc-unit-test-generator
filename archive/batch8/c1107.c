#include <stdio.h>
struct Point { union { struct { int x,y; }; int axis[2]; }; };
static int manhattan(const struct Point *a,const struct Point *b){int dx=a->x-b->x,dy=a->y-b->y;return (dx<0?-dx:dx)+(dy<0?-dy:dy);}
int main(void){struct Point a={{.x=2,.y=7}},b={{.x=8,.y=4}};int actual=manhattan(&a,&b);printf("c1107 point=%d\n",actual);return actual!=9;}
