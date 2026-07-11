#include <stdio.h>
struct Point{int x;int y;};
struct Shape{int kind;union{struct Point point;int radius;};};
int main(void){struct Shape s={1,{.point={3,4}}};printf("c1101 anon=%d,%d\n",s.point.x,s.point.y);return 0;}
