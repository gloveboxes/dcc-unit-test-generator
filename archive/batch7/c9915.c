#include <stdio.h>
static void negate(int n,int a[n]){int i;for(i=0;i<n;++i)a[i]=-a[i];}
int main(void){int a[3]={2,-4,6};negate(3,a);printf("c9915 negate=%d,%d\n",a[0],a[1]);return 0;}
