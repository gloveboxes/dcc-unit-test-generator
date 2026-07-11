#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union FourCC { uint32_t code; struct { char first,second,third,fourth; }; };
int main(void){union FourCC tag={.first='D',.second='A',.third='T',.fourth='A'};printf("c1119 fourcc=%c%c%c%c\n",tag.first,tag.second,tag.third,tag.fourth);return tag.code!=(uint32_t)0x41544144UL;}
