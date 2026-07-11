#include <stdio.h>
static int count_runs(int n,const int a[n]){int i,r=0;for(i=1;i<n;++i)if(a[i]!=a[i-1])++r;return n? r+1:0;}
int main(void){int a[6]={1,1,2,2,3,1};printf("c9932 runs=%d\n",count_runs(6,a));return 0;}
