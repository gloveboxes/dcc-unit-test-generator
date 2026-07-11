#include <stdio.h>
struct Pair{int x;int y;};
static struct Pair add(struct Pair a,struct Pair b){return (struct Pair){a.x+b.x,a.y+b.y};}
int main(void){struct Pair p=add((struct Pair){2,5},(struct Pair){7,-1});printf("c9902 compound=%d,%d\n",p.x,p.y);return 0;}
