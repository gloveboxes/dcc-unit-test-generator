#include <stdio.h>
struct Vector{int x;int y;};
static int cross(struct Vector a,struct Vector b){return a.x*b.y-a.y*b.x;}
int main(void){printf("c9915 vector=%d\n",cross((struct Vector){3,4},(struct Vector){-2,5}));return 0;}
