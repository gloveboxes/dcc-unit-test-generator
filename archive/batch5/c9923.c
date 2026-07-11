#include <stdio.h>
static int reverse_copy(int n,const int in[n],int out[n]){int i;for(i=0;i<n;++i)out[i]=in[n-i-1];return out[0];}
int main(void){int a[4]={2,4,6,8},b[4];reverse_copy(4,a,b);printf("c9923 reverse=%d,%d\n",b[0],b[3]);return 0;}
