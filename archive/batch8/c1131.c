#include <stdio.h>
struct Counter { union { unsigned short raw; struct { unsigned value:12; unsigned overflow:1; unsigned reserved:3; }; }; };
static void increment(struct Counter *c){if(c->value==4095){c->value=0;c->overflow=1;}else ++c->value;}
int main(void){struct Counter c;c.raw=0;c.value=4095;increment(&c);printf("c1131 counter=%u,%u\n",c.value,c.overflow);return !(c.value==0&&c.overflow==1);}
