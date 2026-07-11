#include <stdio.h>
struct Header{struct{unsigned version:4;unsigned kind:4;};unsigned length;};
int main(void){struct Header header={.version=3,.kind=2,.length=128};printf("c1110 header=%u,%u,%u\n",header.version,header.kind,header.length);return 0;}
