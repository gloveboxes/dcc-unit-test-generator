#include <stdio.h>

struct Point { int x,y; };struct Affine { int a,b,c,d,tx,ty; };
static struct Point apply(const struct Affine *m,const struct Point *p){struct Point r={.x=m->a*p->x+m->b*p->y+m->tx,.y=m->c*p->x+m->d*p->y+m->ty};return r;}
int main(void){const struct Affine *m=&(struct Affine){.a=0,.b=-1,.c=1,.d=0,.tx=10,.ty=3};struct Point p=apply(m,&(struct Point){.x=4,.y=7});printf("c9904 affine=%d,%d\n",p.x,p.y);return !(p.x==3&&p.y==7);}
