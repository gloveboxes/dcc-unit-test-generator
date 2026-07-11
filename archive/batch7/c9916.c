#include <stdio.h>
static int sum_squares(int n,const int a[n]){int i,r=0;for(i=0;i<n;++i)r+=a[i]*a[i];return r;}
int main(void){int a[3]={2,3,4};printf("c9916 sqsum=%d\n",sum_squares(3,a));return 0;}
