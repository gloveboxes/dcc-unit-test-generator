#include <stdio.h>
int main(void){int a[6]={3,1,4,1,5,9},i,j,temp,inv=0;for(i=0;i<6;++i)for(j=i+1;j<6;++j)if(a[i]>a[j])++inv;for(i=0;i<6;++i)for(j=i+1;j<6;++j)if(a[i]>a[j]){temp=a[i];a[i]=a[j];a[j]=temp;}printf("c8907 inversions=%d last=%d\n",inv,a[5]);return 0;}
