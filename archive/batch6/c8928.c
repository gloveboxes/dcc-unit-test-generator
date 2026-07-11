#include <stdio.h>
static int sign(int n){return n>0?1:n<0?-1:0;}
int main(void){printf("c8928 sign=%d,%d,%d\n",sign(-4),sign(0),sign(9));return 0;}
