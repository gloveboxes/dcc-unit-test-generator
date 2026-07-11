#include <stdio.h>

enum Op { SEEK,TRANSFER,PAUSE };struct Operation { enum Op op; union { struct { int cylinder,head; }; struct { int source,target,count; }; int ticks; }; };
static int work(const struct Operation *p){if(p->op==SEEK)return p->cylinder+p->head;if(p->op==TRANSFER)return p->count+(p->source!=p->target);return p->ticks;}
int main(void){struct Operation q[3]={{.op=SEEK,.cylinder=12,.head=1},{.op=TRANSFER,.source=2,.target=4,.count=16},{.op=PAUSE,.ticks=5}};int total=0;for(int i=0;i<3;++i)total+=work(&q[i]);printf("c1110 operations=%d,%d\n",total,q[1].count);return !(total==35&&q[1].count==16);}
