#include <stdio.h>
static void bubble_sort(int* a,int n){int i,j,t;for(i=0;i<n-1;++i)for(j=0;j<n-i-1;++j)if(a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}}
int main(void){int a[4]={4,1,3,2};bubble_sort(a,4);printf("c8921 sort=%d,%d\n",a[0],a[3]);return 0;}
