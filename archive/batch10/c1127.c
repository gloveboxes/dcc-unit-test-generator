#include <stdio.h>

enum CellKind { EMPTY,OCCUPIED,RESERVED };struct Cell { enum CellKind kind;union { struct { int entity,energy; };struct { int owner,until; }; }; };
static int score(const struct Cell *c){if(c->kind==EMPTY)return 0;if(c->kind==OCCUPIED)return c->entity+c->energy;return c->until-c->owner;}
int main(void){struct Cell row[4]={{.kind=EMPTY},{.kind=OCCUPIED,.entity=7,.energy=12},{.kind=RESERVED,.owner=3,.until=15},{.kind=OCCUPIED,.entity=2,.energy=6}};int total=0;for(int i=0;i<4;++i)total+=score(&row[i]);printf("c1127 cells=%d,%d\n",total,row[2].until);return !(total==39&&row[2].until==15);}
