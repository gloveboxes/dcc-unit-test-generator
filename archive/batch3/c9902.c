#include <stdio.h>
struct Vec{int x;int y;};
static struct Vec add(struct Vec a,struct Vec b){return (struct Vec){a.x+b.x,a.y+b.y};}
int main(void){struct Vec v;v=add((struct Vec){3,4},(struct Vec){-1,6});printf("c9902 vector=%d,%d\n",v.x,v.y);return 0;}
