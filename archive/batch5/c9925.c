#include <stdio.h>
static int count_if(int n,const int a[n],int threshold){int i,r=0;for(i=0;i<n;++i)if(a[i]>threshold)++r;return r;}
int main(void){int a[6]={2,9,4,8,1,7};printf("c9925 count=%d\n",count_if(6,a,5));return 0;}
