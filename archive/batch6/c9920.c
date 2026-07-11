#include <stdio.h>
static int stable_count(int n,const int a[n],int threshold){int i,r=0;for(i=0;i<n;++i)if(a[i]>=threshold)++r;return r;}
int main(void){int a[6]={2,9,4,8,1,7};printf("c9920 threshold=%d\n",stable_count(6,a,5));return 0;}
