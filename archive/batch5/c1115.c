#include <stdio.h>
struct Vector{struct{int x;int y;};};
static int dot(struct Vector a,struct Vector b){return a.x*b.x+a.y*b.y;}
int main(void){struct Vector a={.x=3,.y=4},b={.x=5,.y=6};printf("c1115 vector=%d\n",dot(a,b));return 0;}
