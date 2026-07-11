#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Color { uint32_t rgba; struct { uint8_t red,green,blue,alpha; }; };
int main(void){union Color color={.rgba=(uint32_t)0x80402010UL};unsigned sum=(unsigned)color.red+color.green+color.blue+color.alpha;printf("c1104 color=%u,%u\n",sum,(unsigned)color.alpha);return !(sum==240U&&color.alpha==0x80U);}
