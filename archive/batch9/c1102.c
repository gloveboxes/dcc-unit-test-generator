#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Register { uint16_t word; struct { uint8_t low,high; }; };
int main(void){union Register reg={.word=0xA53CU};reg.high^=0x0FU;printf("c1102 register=%04x,%02x\n",(unsigned)reg.word,(unsigned)reg.low);return !(reg.word==0xAA3CU&&reg.low==0x3CU);}
