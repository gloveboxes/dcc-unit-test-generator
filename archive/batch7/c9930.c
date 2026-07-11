#include <stdio.h>
static void reverse_var(int n,int a[n]){int i,t;for(i=0;i<n/2;++i){t=a[i];a[i]=a[n-1-i];a[n-1-i]=t;}}
int main(void){int a[5]={1,2,3,4,5};reverse_var(5,a);printf("c9930 rev=%d,%d\n",a[0],a[4]);return 0;}
