#include <stdio.h>
static void scale(int n,int factor,int a[n]){int i;for(i=0;i<n;++i)a[i]*=factor;}
int main(void){int a[4]={1,3,5,7};scale(4,3,a);printf("c9912 scale=%d,%d\n",a[0],a[3]);return 0;}
