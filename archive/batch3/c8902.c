#include <stdio.h>
static unsigned crc16(const unsigned char *p,int n){unsigned crc;int i,j;crc=65535;for(i=0;i<n;++i){crc^=p[i];for(j=0;j<8;++j)crc=(crc&1)?(crc>>1)^40961:crc>>1;}return crc;}
int main(void){static const unsigned char text[]="123456789";printf("c8902 crc=%u\n",crc16(text,9));return 0;}
