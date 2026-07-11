#include <stdio.h>
struct Header{unsigned version:3;unsigned type:5;unsigned length:8;};
int main(void){struct Header h={5,17,200};printf("c1104 header=%u,%u,%u\n",h.version,h.type,h.length);return 0;}
