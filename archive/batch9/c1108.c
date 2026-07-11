#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Version { uint32_t packed; struct { uint8_t patch,minor,major,flags; }; };
int main(void){union Version version={.packed=(uint32_t)0x01020304UL};printf("c1108 version=%u.%u.%u\n",(unsigned)version.major,(unsigned)version.minor,(unsigned)version.patch);return !(version.major==2U&&version.minor==3U&&version.patch==4U);}
