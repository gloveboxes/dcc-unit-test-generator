#include <stdio.h>
static int sum(const int *a,int n){int i,r=0;for(i=0;i<n;++i)r+=a[i];return r;}
int main(void){int a[5]={2,4,6,8,10};printf("c8901 sum=%d\n",sum(a,5));return 0;}
