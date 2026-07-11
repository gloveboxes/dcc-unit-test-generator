#include <stdio.h>
static int checksum(int n,const unsigned char bytes[n]){int i,total;total=0;for(i=0;i<n;++i)total=(total+bytes[i]*(i+1))%256;return total;}
int main(void){unsigned char bytes[5]={3,1,4,1,5};printf("c9916 vla=%d\n",checksum(5,bytes));return 0;}
