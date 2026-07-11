#include <stdio.h>
static int count_value(int n,const int a[n],int value){int i,r=0;for(i=0;i<n;++i)if(a[i]==value)++r;return r;}
int main(void){int a[7]={2,4,2,8,2,6,2};printf("c9911 count=%d\n",count_value(7,a,2));return 0;}
