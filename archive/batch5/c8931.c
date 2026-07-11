#include <stdio.h>
static int paths(int r,int c){int a[8][8],i,j;for(i=0;i<r;++i)for(j=0;j<c;++j)a[i][j]=1;for(i=1;i<r;++i)for(j=1;j<c;++j)a[i][j]=a[i-1][j]+a[i][j-1];return a[r-1][c-1];}
int main(void){printf("c8931 paths=%d\n",paths(4,5));return 0;}
