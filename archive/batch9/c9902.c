#include <stdio.h>
struct Point { int x,y; };
static int distance2(const struct Point *a,const struct Point *b){int dx=a->x-b->x;int dy=a->y-b->y;return dx*dx+dy*dy;}
int main(void){const struct Point *origin=&(struct Point){.x=0,.y=0};const struct Point *site=&(struct Point){.y=4,.x=3};int d=distance2(origin,site);printf("c9902 distance=%d\n",d);return d!=25;}
