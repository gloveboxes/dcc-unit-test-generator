#include <stdio.h>
static int hist(int n,const int a[n],int bins[4]){int i;for(i=0;i<4;++i)bins[i]=0;for(i=0;i<n;++i)if(a[i]>=0&&a[i]<4)++bins[a[i]];return n;}
int main(void){int a[6]={0,1,1,3,3,3},b[4];hist(6,a,b);printf("c9913 hist=%d,%d\n",b[1],b[3]);return 0;}
