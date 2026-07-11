#include <stdio.h>
struct Header{struct{unsigned version:4;unsigned flags:4;};unsigned length;};
int main(void){struct Header h;h.version=3;h.flags=9;h.length=128;printf("c1103 header=%u/%u/%u\n",h.version,h.flags,h.length);return 0;}
