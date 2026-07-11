#include <stdio.h>
static int dot(int n,const int * restrict a,const int * restrict b){int i,total;total=0;for(i=0;i<n;++i)total+=a[i]*b[i];return total;}
int main(void){int a[4]={2,3,4,5};int b[4]={7,5,3,1};printf("c9905 dot=%d\n",dot(4,a,b));return 0;}
