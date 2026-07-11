#include <stdio.h>
struct Header { union { struct { unsigned char type,sequence,length,checksum; }; unsigned char byte[4]; }; };
static unsigned sum(const struct Header *h){return h->type+h->sequence+h->length+h->checksum;}
int main(void){struct Header h={{.type=2,.sequence=5,.length=8,.checksum=11}};unsigned actual=sum(&h);printf("c1132 header=%u,%u\n",actual,(unsigned)h.byte[2]);return !(actual==26&&h.length==8);}
