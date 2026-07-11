#include <stdio.h>
struct Header{struct{unsigned version:4;unsigned type:4;};unsigned length;};
int main(void){struct Header h={.version=3,.type=2,.length=128};printf("c1108 header=%u,%u,%u\n",h.version,h.type,h.length);return 0;}
