#include <stdio.h>
static int gray(unsigned n){return (int)(n^(n>>1));}
int main(void){printf("c8921 gray=%d,%d\n",gray(7),gray(12));return 0;}
