#include <stdio.h>
int main(void){int a[5]={7,3,9,2,6},i,j,pass,temp;for(pass=0;pass<4;++pass)for(i=0;i<4-pass;++i)if(a[i]>a[i+1]){temp=a[i];a[i]=a[i+1];a[i+1]=temp;}j=0;for(i=0;i<5;++i)j=j*10+a[i];printf("c8914 bubble=%d\n",j);return 0;}
