#include <stdio.h>
static int diagonal(int n,const int a[n][n]){int i,r=0;for(i=0;i<n;++i)r+=a[i][i];return r;}
int main(void){int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};printf("c9928 diagonal=%d\n",diagonal(3,a));return 0;}
