#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Fixed { int16_t raw; struct { uint8_t fraction; int8_t whole; }; };
int main(void){union Fixed value={.raw=(int16_t)0x0340};int hundredths=(int)value.whole*100+(unsigned)value.fraction*100/256;printf("c1112 fixed=%d\n",hundredths);return hundredths!=325;}
