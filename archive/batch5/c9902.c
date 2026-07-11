#include <stdio.h>
static struct Point{int x;int y;} add(struct Point a,struct Point b){return (struct Point){a.x+b.x,a.y+b.y};}
int main(void){struct Point p=add((struct Point){2,3},(struct Point){4,5});printf("c9902 compound=%d,%d\n",p.x,p.y);return 0;}
