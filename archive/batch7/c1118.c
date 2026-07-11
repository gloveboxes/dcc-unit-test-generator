#include <stdio.h>
struct Coord3{union{struct{int x;int y;int z;};int c[3];};};
int main(void){struct Coord3 c={{.x=10,.y=20,.z=30}};printf("c1118 c3=%d,%d,%d\n",c.c[0],c.c[1],c.c[2]);return 0;}
