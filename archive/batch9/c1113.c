#include <stdio.h>
struct Transform { union { struct { int m00,m01,m10,m11; }; int cell[4]; }; };
static void apply(const struct Transform *t,int x,int y,int *outx,int *outy){*outx=t->m00*x+t->m01*y;*outy=t->m10*x+t->m11*y;}
int main(void){struct Transform t={.cell={0,-1,1,0}};int x,y;apply(&t,3,4,&x,&y);printf("c1113 transform=%d,%d\n",x,y);return !(x==-4&&y==3);}
