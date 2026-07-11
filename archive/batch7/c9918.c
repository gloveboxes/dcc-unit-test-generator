#include <stdio.h>
static void shift_right(int n,int a[n]){int i;for(i=n-1;i>0;--i)a[i]=a[i-1];a[0]=0;}
int main(void){int a[4]={1,2,3,4};shift_right(4,a);printf("c9918 shr=%d,%d\n",a[0],a[3]);return 0;}
