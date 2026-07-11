#include <stdio.h>
static int clamp_all(int n,int a[n],int lo,int hi){int i;for(i=0;i<n;++i){if(a[i]<lo)a[i]=lo;if(a[i]>hi)a[i]=hi;}return a[n-1];}
int main(void){int a[4]={-2,3,9,20},last;last=clamp_all(4,a,0,10);printf("c9921 clamp=%d,%d\n",last,a[3]);return 0;}
