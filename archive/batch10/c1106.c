#include <stdio.h>

enum SegmentKind { STRAIGHT,TURN };struct Segment { enum SegmentKind kind; union { struct { int distance,speed; }; struct { int angle,radius; }; }; };
static int cost(const struct Segment *s){return s->kind==STRAIGHT?s->distance*10/s->speed:(s->angle<0?-s->angle:s->angle)+s->radius;}
int main(void){struct Segment path[3]={{.kind=STRAIGHT,.distance=120,.speed=30},{.kind=TURN,.angle=-90,.radius=8},{.kind=STRAIGHT,.distance=50,.speed=25}};int total=0;for(int i=0;i<3;++i)total+=cost(&path[i]);printf("c1106 route=%d,%d\n",total,path[1].radius);return !(total==158&&path[1].radius==8);}
