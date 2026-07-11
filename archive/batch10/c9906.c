#include <stdio.h>
#include <stdbool.h>

struct Circle { int x,y,r; };struct Point { int x,y; };
static bool inside(const struct Circle *c,const struct Point *p){int dx=p->x-c->x,dy=p->y-c->y;return dx*dx+dy*dy<=c->r*c->r;}
int main(void){const struct Circle *zone=&(struct Circle){.x=5,.y=-2,.r=6};bool a=inside(zone,&(struct Point){8,2}),b=inside(zone,&(struct Point){12,-2});printf("c9906 geofence=%d,%d\n",(int)a,(int)b);return !(a&&!b);}
