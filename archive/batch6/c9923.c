#include <stdio.h>
static int sum_even(int n,const int a[n]){int i,r=0;for(i=0;i<n;++i)if(a[i]%2==0)r+=a[i];return r;}
int main(void){int a[6]={1,2,3,4,5,6};printf("c9923 even=%d\n",sum_even(6,a));return 0;}
