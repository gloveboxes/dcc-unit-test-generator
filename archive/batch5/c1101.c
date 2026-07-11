#include <stdio.h>
struct Point{struct{int x;int y;};};
int main(void){struct Point p={.x=4,.y=9};printf("c1101 point=%d,%d\n",p.x,p.y);return 0;}
