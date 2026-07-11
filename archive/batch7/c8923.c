#include <stdio.h>
static int binary_search(const int* a,int n,int k){int l=0,r=n-1,m;while(l<=r){m=(l+r)/2;if(a[m]==k)return m;if(a[m]<k)l=m+1;else r=m-1;}return -1;}
int main(void){int a[5]={2,4,6,8,10};printf("c8923 binsearch=%d,%d\n",binary_search(a,5,6),binary_search(a,5,7));return 0;}
