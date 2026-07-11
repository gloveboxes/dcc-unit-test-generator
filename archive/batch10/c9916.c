#include <stdio.h>
#include <stdint.h>

static inline uint16_t readbe(const uint8_t *p){return (uint16_t)((uint16_t)p[0]<<8)|p[1];}
static uint32_t accumulate(const uint8_t *p,int pairs){uint32_t sum=0;for(int i=0;i<pairs;++i)sum=sum*17U+readbe(p+i*2);return sum;}
int main(void){uint8_t data[6]={0x01,0x02,0x12,0x34,0x00,0xFF};uint32_t sum=accumulate(data,3);printf("c9916 bigendian=%u,%lu\n",(unsigned)readbe(data+2),(unsigned long)sum);return !(readbe(data+2)==0x1234U&&sum==154037U);}
