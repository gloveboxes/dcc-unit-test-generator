#include <stdio.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
struct Word { union { unsigned short value; struct { unsigned char low,high; }; }; };
int main(void){struct Word w;w.value=0x1234;printf("c1104 word=%02x,%02x\n",w.low,w.high);return !(w.low==0x34&&w.high==0x12);}
