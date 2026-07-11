#include <stdio.h>
static int maximum(int rows,int cols,const int a[rows][cols]){int r,c,best=a[0][0];for(r=0;r<rows;++r)for(c=0;c<cols;++c)if(a[r][c]>best)best=a[r][c];return best;}
int main(void){int a[2][3]={{2,9,4},{8,1,7}};printf("c9909 matrix=%d\n",maximum(2,3,a));return 0;}
