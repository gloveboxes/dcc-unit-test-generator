#include <stdio.h>
static int dot(int n,const int a[n],const int b[n]){int i,r=0;for(i=0;i<n;++i)r+=a[i]*b[i];return r;}
int main(void){int a[3]={2,3,4},b[3]={5,6,7};printf("c9909 dot=%d\n",dot(3,a,b));return 0;}
