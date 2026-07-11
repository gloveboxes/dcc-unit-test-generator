#include <stdio.h>
struct Coordinate { union { struct { int row,column; }; struct { int y,x; }; }; };
int main(void){struct Coordinate c={{.row=4,.column=9}};printf("c1125 coordinate=%d,%d\n",c.x,c.y);return !(c.x==9&&c.y==4);}
