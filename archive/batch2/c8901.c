#include <stdio.h>
static void down(int *a, int n, int i){int child, t; for(;;){child=2*i+1;if(child>=n)break;if(child+1<n&&a[child+1]>a[child])++child;if(a[i]>=a[child])break;t=a[i];a[i]=a[child];a[child]=t;i=child;}}
int main(void){int a[7]={6,1,9,2,8,3,5},i,t,total=0;for(i=3;i>=0;--i)down(a,7,i);for(i=6;i>0;--i){t=a[0];a[0]=a[i];a[i]=t;down(a,i,0);}for(i=0;i<7;++i)total=total*10+a[i];printf("c8901 heap=%d\n",total);return 0;}
