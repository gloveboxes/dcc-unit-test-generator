#include <stdio.h>
struct Matrix { int v[2][2]; };
static int determinant(struct Matrix m) { return m.v[0][0]*m.v[1][1]-m.v[0][1]*m.v[1][0]; }
int main(void) { int actual=determinant((struct Matrix){{{4,7},{2,6}}}); printf("c9918 determinant=%d\n",actual); return actual!=10; }
