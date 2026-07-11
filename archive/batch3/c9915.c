#include <stdio.h>
static void rotate(int n,int * restrict a,int * restrict b){int i,t;for(i=0;i<n;++i){t=a[i];a[i]=b[i];b[i]=t;}}
int main(void){int a[3]={1,2,3};int b[3]={8,9,10};rotate(3,a,b);printf("c9915 restrict=%d,%d/%d,%d\n",a[0],a[2],b[0],b[2]);return 0;}
