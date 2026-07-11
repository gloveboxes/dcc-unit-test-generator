#include <stdio.h>
struct Bcd { union { unsigned char raw; struct { unsigned low:4; unsigned high:4; }; }; };
static int decimal(const struct Bcd *b){return b->high*10+b->low;}
int main(void){struct Bcd b;b.raw=0x42;int actual=decimal(&b);printf("c1111 bcd=%d\n",actual);return actual!=42;}
