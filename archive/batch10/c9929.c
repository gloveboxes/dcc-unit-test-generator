#include <stdio.h>

struct Point { int x,y; };static int manhattan(const struct Point *a,const struct Point *b){int dx=a->x-b->x,dy=a->y-b->y;return (dx<0?-dx:dx)+(dy<0?-dy:dy);}
static int path(const struct Point *p,int n){int total=0;for(int i=1;i<n;++i)total+=manhattan(&p[i-1],&p[i]);return total;}
int main(void){struct Point route[5]={{0,0},{3,2},{-1,5},{2,7},{2,1}};int length=path(route,5);printf("c9929 route=%d\n",length);return length!=23;}
