#include <stdio.h>
#include <stdint.h>
static uint16_t encode_pair(uint8_t hi,uint8_t lo){return (uint16_t)(((uint16_t)hi<<8)|lo);}
int main(void){printf("c9922 pair=%u,%u\n",(unsigned)encode_pair(0x12,0x34),(unsigned)encode_pair(0xAB,0xCD));return 0;}
