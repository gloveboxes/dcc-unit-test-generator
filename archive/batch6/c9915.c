#include <stdio.h>
static int min_value(int n,const int a[n]){int i,r=a[0];for(i=1;i<n;++i)if(a[i]<r)r=a[i];return r;}
int main(void){int a[5]={8,3,12,4,9};printf("c9915 min=%d\n",min_value(5,a));return 0;}
