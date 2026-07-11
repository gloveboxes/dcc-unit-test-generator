#include <stdio.h>
static int range_sum(int n,const int a[n],int lo,int hi){int i,r=0;for(i=lo;i<=hi;++i)r+=a[i];return r;}
int main(void){int a[6]={1,2,3,4,5,6};printf("c9930 range=%d\n",range_sum(6,a,1,4));return 0;}
