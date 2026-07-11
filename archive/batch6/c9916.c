#include <stdio.h>
static int reverse_in_place(int n,int a[n]){int i,t;for(i=0;i<n/2;++i){t=a[i];a[i]=a[n-i-1];a[n-i-1]=t;}return a[0];}
int main(void){int a[4]={2,4,6,8};reverse_in_place(4,a);printf("c9916 reverse=%d,%d\n",a[0],a[3]);return 0;}
