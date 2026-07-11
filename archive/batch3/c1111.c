#include <stdio.h>
struct Header{union{unsigned word;struct{unsigned kind:4;unsigned flags:4;unsigned length:8;};};};
int main(void){struct Header h={.kind=3,.flags=5,.length=200};printf("c1111 header=%u,%u,%u/%u\n",h.kind,h.flags,h.length,h.word);return 0;}
