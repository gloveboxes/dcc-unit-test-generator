#include <stdio.h>
/* Byte overlay assumes little-endian representation. */
struct Version { union { unsigned short packed; struct { unsigned char minor,major; }; }; };
int main(void){struct Version v;v.major=2;v.minor=7;printf("c1109 version=%u.%u,%04x\n",v.major,v.minor,v.packed);return !(v.major==2&&v.minor==7);}
