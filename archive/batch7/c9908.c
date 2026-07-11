#include <stdio.h>
static int trace(int n,const int a[n][n]){int i,r=0;for(i=0;i<n;++i)r+=a[i][i];return r;}
int main(void){int a[2][2]={{1,2},{3,4}};printf("c9908 trace=%d\n",trace(2,a));return 0;}
