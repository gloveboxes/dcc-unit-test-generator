#include <stdio.h>
static void saxpy(int n,int factor,const int * restrict x,int * restrict y){int i;for(i=0;i<n;++i)y[i]+=factor*x[i];}
int main(void){int x[4]={1,2,3,4},y[4]={5,5,5,5},i; saxpy(4,3,x,y);printf("c9905 restrict=");for(i=0;i<4;++i)printf("%d",y[i]);putchar('\n');return 0;}
