#include <stdio.h>
static void saxpy(int n,int scale,const int * restrict x,int * restrict y){int i;for(i=0;i<n;++i)y[i]+=scale*x[i];}
int main(void){int x[4]={1,2,3,4},y[4]={5,5,5,5};saxpy(4,3,x,y);printf("c9905 saxpy=%d,%d,%d,%d\n",y[0],y[1],y[2],y[3]);return 0;}
