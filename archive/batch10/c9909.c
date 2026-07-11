#include <stdio.h>
#include <stdbool.h>

static int peaks(int rows,int cols,const int a[rows][4]){bool peak[rows][4];int count=0;for(int r=0;r<rows;++r)for(int c=0;c<cols;++c){int v=a[r][c];peak[r][c]=(r==0||v>a[r-1][c])&&(r+1==rows||v>a[r+1][c])&&(c==0||v>a[r][c-1])&&(c+1==cols||v>a[r][c+1]);count+=peak[r][c];}return count;}
int main(void){int a[4][4]={{1,5,2,1},{3,2,7,4},{2,8,1,6},{1,2,4,3}};int n=peaks(4,4,a);printf("c9909 peaks=%d\n",n);return n!=6;}
