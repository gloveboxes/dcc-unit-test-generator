#include <stdio.h>
static unsigned char crc8(const unsigned char *data,int n){unsigned char crc=0;int i,b;for(i=0;i<n;++i){crc^=data[i];for(b=0;b<8;++b)crc=(unsigned char)(crc&0x80?(crc<<1)^0x07:(crc<<1));}return crc;}
int main(void){static const unsigned char data[]={1,2,3,4,5};unsigned char c=crc8(data,5);printf("c8912 crc8=%02x\n",(unsigned)c);return c!=0xBCU;}
