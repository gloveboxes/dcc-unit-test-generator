#include <stdio.h>
static int total(int n,const int a[n]){int i,r=0;for(i=0;i<n;++i)r+=a[i];return r;}
int main(void){int a[5]={2,4,6,8,10};printf("c9904 vla=%d\n",total(5,a));return 0;}
