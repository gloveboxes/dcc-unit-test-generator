#include <stdio.h>
static int sum_rows(int rows,int cols,const int a[rows][cols]){int r,c,total=0;for(r=0;r<rows;++r)for(c=0;c<cols;++c)total+=a[r][c];return total;}
int main(void){int a[2][3]={{1,2,3},{4,5,6}};printf("c9904 vla=%d\n",sum_rows(2,3,a));return 0;}
