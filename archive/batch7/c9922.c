#include <stdio.h>
static void zip_add(int n,const int a[n],const int b[n],int c[n]){int i;for(i=0;i<n;++i)c[i]=a[i]+b[i];}
int main(void){int a[3]={1,2,3},b[3]={4,5,6},c[3];zip_add(3,a,b,c);printf("c9922 zip=%d,%d\n",c[0],c[2]);return 0;}
