#include <stdio.h>
static void insertion_sort(int *a,int n){int i,j,value;for(i=1;i<n;++i){value=a[i];j=i;while(j>0&&a[j-1]>value){a[j]=a[j-1];--j;}a[j]=value;}}
int main(void){int a[6]={9,2,7,1,6,3};insertion_sort(a,6);printf("c8907 sort=%d,%d,%d,%d,%d,%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);return 0;}
