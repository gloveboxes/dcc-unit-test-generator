#include <stdio.h>
#include <stdint.h>
static uint16_t pack(uint8_t hi,uint8_t lo){return (uint16_t)(((uint16_t)hi<<8)|lo);}
int main(void){printf("c9929 pack=%u,%u\n",(unsigned)pack(0x12,0x34),(unsigned)pack(0xAB,0xCD));return 0;}
