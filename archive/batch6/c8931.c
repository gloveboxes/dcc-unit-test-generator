#include <stdio.h>
static int count_between(const int *a,int n,int lo,int hi){int i,r=0;for(i=0;i<n;++i)if(a[i]>=lo&&a[i]<=hi)++r;return r;}
int main(void){int a[6]={1,4,7,9,12,15};printf("c8931 range=%d\n",count_between(a,6,5,12));return 0;}
