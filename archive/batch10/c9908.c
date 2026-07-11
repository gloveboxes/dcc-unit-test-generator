#include <stdio.h>

static int rectangle_sum(int rows,int cols,const int a[rows][4],int r0,int c0,int r1,int c1){int prefix[rows+1][5];for(int r=0;r<=rows;++r)for(int c=0;c<=cols;++c)prefix[r][c]=0;for(int r=1;r<=rows;++r)for(int c=1;c<=cols;++c)prefix[r][c]=a[r-1][c-1]+prefix[r-1][c]+prefix[r][c-1]-prefix[r-1][c-1];return prefix[r1][c1]-prefix[r0][c1]-prefix[r1][c0]+prefix[r0][c0];}
int main(void){int a[3][4]={{2,1,3,0},{4,2,1,5},{0,3,2,1}};int x=rectangle_sum(3,4,a,1,1,3,4);printf("c9908 integral=%d\n",x);return x!=14;}
