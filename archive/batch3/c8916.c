#include <stdio.h>
static int paths(int r,int c){int a[6][6];int i,j;for(i=0;i<r;++i)for(j=0;j<c;++j)a[i][j]=1;if(r>1)for(i=1;i<r;++i)for(j=1;j<c;++j)a[i][j]=a[i-1][j]+a[i][j-1];return a[r-1][c-1];}
int main(void){printf("c8916 gridpaths=%d\n",paths(4,5));return 0;}
