#include <stdio.h>
static int fixed_mul(int a,int b){return (a*b+50)/100;}
int main(void){printf("c8908 fixed=%d,%d\n",fixed_mul(125,80),fixed_mul(333,250));return 0;}
