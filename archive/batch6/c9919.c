#include <stdio.h>
static int row_sum(int cols,const int row[cols]){int i,r=0;for(i=0;i<cols;++i)r+=row[i];return r;}
int main(void){int a[4]={1,3,5,7};printf("c9919 rowsum=%d\n",row_sum(4,a));return 0;}
