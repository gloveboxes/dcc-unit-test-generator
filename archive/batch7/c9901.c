#include <stdio.h>
struct Range{int min;int max;};
static struct Range bounds(int n,const int a[n]){struct Range r={a[0],a[0]};int i;for(i=1;i<n;++i){if(a[i]<r.min)r.min=a[i];if(a[i]>r.max)r.max=a[i];}return r;}
int main(void){int a[4]={7,2,9,4};struct Range r=bounds(4,a);printf("c9901 bounds=%d,%d\n",r.min,r.max);return 0;}
