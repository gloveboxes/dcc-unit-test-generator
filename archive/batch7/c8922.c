#include <stdio.h>
static void insertion_sort(int* a,int n){int i,k,j;for(i=1;i<n;++i){k=a[i];j=i-1;while(j>=0&&a[j]>k){a[j+1]=a[j];--j;}a[j+1]=k;}}
int main(void){int a[4]={4,1,3,2};insertion_sort(a,4);printf("c8922 ins=%d,%d\n",a[0],a[3]);return 0;}
