#include <stdio.h>
struct Line{union{struct{int p1;int p2;};int p[2];};};
int main(void){struct Line l={{.p1=5,.p2=10}};printf("c1130 line=%d,%d\n",l.p[0],l.p[1]);return 0;}
