#include <stdio.h>
static int crc16(const unsigned char* d,int n){unsigned int c=0xffff;int i,j;for(i=0;i<n;++i){c^=d[i];for(j=0;j<8;++j)c=c&1?(c>>1)^0xa001:c>>1;}return c;}
int main(void){const unsigned char b[]="12345";printf("c8925 crc=%04x\n",crc16(b,5));return 0;}
