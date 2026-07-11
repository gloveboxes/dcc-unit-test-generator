#include <stdio.h>
static int next_permutation(int a[],int n){int i=n-2;while(i>=0&&a[i]>=a[i+1])--i;if(i<0)return 0;int j=n-1;while(a[j]<=a[i])--j;int t=a[i];a[i]=a[j];a[j]=t;int lo=i+1,hi=n-1;while(lo<hi){t=a[lo];a[lo++]=a[hi];a[hi--]=t;}return 1;}
int main(void){int a[3]={1,2,3},count=1;while(next_permutation(a,3))++count;printf("c8932 perms=%d\n",count);return count!=6;}
