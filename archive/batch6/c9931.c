#include <stdio.h>
static int rotate_left(int n,int a[n]){int i,t=a[0];for(i=0;i<n-1;++i)a[i]=a[i+1];a[n-1]=t;return a[0];}
int main(void){int a[4]={1,2,3,4};rotate_left(4,a);printf("c9931 rotate=%d,%d\n",a[0],a[3]);return 0;}
