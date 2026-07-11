#include <stdio.h>
static void add_scaled(int n,int scale,const int * restrict a,int * restrict b){int i;for(i=0;i<n;++i)b[i]+=scale*a[i];}
int main(void){int a[3]={1,2,3},b[3]={4,4,4};add_scaled(3,2,a,b);printf("c9905 restrict=%d,%d,%d\n",b[0],b[1],b[2]);return 0;}
