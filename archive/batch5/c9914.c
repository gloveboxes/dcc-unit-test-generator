#include <stdio.h>
static int rotate(int n,int shift,int a[n]){int i,t;while(shift--){t=a[n-1];for(i=n-1;i>0;--i)a[i]=a[i-1];a[0]=t;}return a[0];}
int main(void){int a[4]={1,2,3,4},first;first=rotate(4,1,a);printf("c9914 rotate=%d,%d\n",first,a[3]);return 0;}
