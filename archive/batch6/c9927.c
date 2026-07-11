#include <stdio.h>
static int average(int n,const int a[n]){int i,r=0;for(i=0;i<n;++i)r+=a[i];return r/n;}
int main(void){int a[5]={3,5,7,9,11};printf("c9927 average=%d\n",average(5,a));return 0;}
