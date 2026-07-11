#include <stdio.h>
static void copy(int n,const int * restrict src,int * restrict dst){int i;for(i=0;i<n;++i)dst[i]=src[i];}
int main(void){int a[4]={2,4,6,8},b[4];copy(4,a,b);printf("c9905 restrict=%d,%d\n",b[0],b[3]);return 0;}
