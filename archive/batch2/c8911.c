#include <stdio.h>
int main(void){int a[5]={1,2,3,4,5},i,j,temp,checksum=0;for(i=0;i<5;++i){j=(i*3+2)%5;temp=a[i];a[i]=a[j];a[j]=temp;}for(i=0;i<5;++i)checksum=checksum*10+a[i];printf("c8911 permute=%d\n",checksum);return 0;}
