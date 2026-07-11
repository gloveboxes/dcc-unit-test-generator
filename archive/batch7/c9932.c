#include <stdio.h>
static int diff_adj(int n,const int a[n]){int i,r=0;for(i=1;i<n;++i)r+=a[i]-a[i-1];return r;}
int main(void){int a[4]={1,3,6,10};printf("c9932 diffadj=%d\n",diff_adj(4,a));return 0;}
