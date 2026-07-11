#include <stdio.h>
#include <stdint.h>
static uint16_t crc16(const uint8_t *data,int count){uint16_t crc=0xFFFFU;for(int i=0;i<count;++i){crc^=(uint16_t)data[i]<<8;for(int bit=0;bit<8;++bit)crc=(uint16_t)((crc&0x8000U)?(crc<<1)^0x1021U:crc<<1);}return crc;}
int main(void){static const uint8_t data[]={'1','2','3','4','5','6','7','8','9'};uint16_t actual=crc16(data,9);printf("c9913 crc=%04x\n",(unsigned)actual);return actual!=0x29B1U;}
