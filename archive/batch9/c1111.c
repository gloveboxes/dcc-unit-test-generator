#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Address { uint32_t value; struct { uint8_t a,b,c,d; }; };
int main(void){union Address address={.a=192,.b=168,.c=1,.d=42};printf("c1111 address=%u.%u.%u.%u\n",(unsigned)address.a,(unsigned)address.b,(unsigned)address.c,(unsigned)address.d);return address.value!=(uint32_t)0x2A01A8C0UL;}
