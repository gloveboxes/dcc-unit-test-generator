#include <stdio.h>
static int dot2(const int a[2],const int b[2]){return a[0]*b[0]+a[1]*b[1];}
int main(void){int a[2]={3,4},b[2]={5,6};printf("c9917 dot=%d\n",dot2(a,b));return 0;}
