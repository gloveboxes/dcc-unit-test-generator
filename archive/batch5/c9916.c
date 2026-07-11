#include <stdio.h>
static int checksum(int n,const unsigned char a[n]){int i,r=0;for(i=0;i<n;++i)r=(r+a[i]*(i+1))%256;return r;}
int main(void){unsigned char a[5]={3,1,4,1,5};printf("c9916 checksum=%d\n",checksum(5,a));return 0;}
