#include <stdio.h>

enum ComponentKind { POSITION,VELOCITY,HEALTH };struct Component { int entity;enum ComponentKind kind;union { struct { int x,y; };struct { int dx,dy; };int health; }; };
static int magnitude(const struct Component *c){if(c->kind==HEALTH)return c->health;return (c->x<0?-c->x:c->x)+(c->y<0?-c->y:c->y);}
int main(void){struct Component c[3]={{.entity=4,.kind=POSITION,.x=7,.y=-2},{.entity=4,.kind=VELOCITY,.dx=-3,.dy=5},{.entity=4,.kind=HEALTH,.health=24}};int total=0;for(int i=0;i<3;++i)total+=magnitude(&c[i]);printf("c1131 components=%d,%d\n",total,c[1].dx);return !(total==41&&c[1].dx==-3);}
