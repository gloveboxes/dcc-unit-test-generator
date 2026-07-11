#include <stdio.h>
static int pad_array(int n,int a[n],int k,int v){int i;for(i=k;i<n;++i)a[i]=v;return n-k;}
int main(void){int a[5]={1,2,0,0,0};pad_array(5,a,2,9);printf("c9926 pad=%d,%d\n",a[2],a[4]);return 0;}
