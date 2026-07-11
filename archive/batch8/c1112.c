#include <stdio.h>
/* Word overlay assumes little-endian representation. */
struct Fixed { union { long raw; struct { unsigned short fraction; short whole; }; }; };
int main(void){struct Fixed f;f.raw=0x00028000L;printf("c1112 fixed=%d,%u\n",f.whole,(unsigned)f.fraction);return !(f.whole==2&&f.fraction==0x8000U);}
