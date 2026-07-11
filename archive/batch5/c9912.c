#include <stdio.h>
static int prefix(int n,const int in[n],int out[n]){int i,r=0;for(i=0;i<n;++i){r+=in[i];out[i]=r;}return r;}
int main(void){int a[4]={1,3,5,7},b[4],total;total=prefix(4,a,b);printf("c9912 prefix=%d,%d\n",total,b[2]);return 0;}
