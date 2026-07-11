#include <stdio.h>
struct Affine{int scale,offset;};static int apply(struct Affine t,int value){return t.scale*value+t.offset;}
int main(void){int actual=apply((struct Affine){3,-2},7);printf("c9932 affine=%d\n",actual);return actual!=19;}
