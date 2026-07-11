#include <stdio.h>
struct Matrix2 { union { struct { int a,b,c,d; }; int cell[2][2]; }; };
static int determinant(const struct Matrix2 *m){return m->a*m->d-m->b*m->c;}
int main(void){struct Matrix2 m={{.a=4,.b=7,.c=2,.d=6}};int actual=determinant(&m);printf("c1121 matrix=%d,%d\n",actual,m.cell[1][1]);return !(actual==10&&m.d==6);}
