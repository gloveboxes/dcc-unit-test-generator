#include <stdio.h>
static int count_zeroes(int n,const int a[n]){int i,r=0;for(i=0;i<n;++i)if(a[i]==0)++r;return r;}
int main(void){int a[6]={0,1,0,2,0,3};printf("c9919 zeroes=%d\n",count_zeroes(6,a));return 0;}
