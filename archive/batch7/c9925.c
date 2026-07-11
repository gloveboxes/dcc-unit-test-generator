#include <stdio.h>
static int filter_pos(int n,const int in[n],int out[n]){int i,k=0;for(i=0;i<n;++i)if(in[i]>0)out[k++]=in[i];return k;}
int main(void){int a[5]={-1,2,-3,4,-5},b[5];int k=filter_pos(5,a,b);printf("c9925 filt=%d,%d\n",k,b[k-1]);return 0;}
