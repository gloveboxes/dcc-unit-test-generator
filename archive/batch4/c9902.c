#include <stdio.h>
struct Point{int x;int y;};
static struct Point midpoint(struct Point a,struct Point b){return (struct Point){(a.x+b.x)/2,(a.y+b.y)/2};}
int main(void){struct Point p=midpoint((struct Point){2,4},(struct Point){8,10});printf("c9902 midpoint=%d,%d\n",p.x,p.y);return 0;}
