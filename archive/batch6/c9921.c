#include <stdio.h>
static int transpose_sum(int n,const int a[n][n]){int i,j,r=0;for(i=0;i<n;++i)for(j=0;j<n;++j)r+=a[i][j];return r;}
int main(void){int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};printf("c9921 matrix=%d\n",transpose_sum(3,a));return 0;}
