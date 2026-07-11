#include <stdio.h>
struct Word{union{unsigned short raw;struct{unsigned char first;unsigned char second;};};};
static unsigned sum_bytes(struct Word w){return w.first+w.second;}
int main(void){struct Word w={{0x3412}};printf("c1112 word=%u,%u\n",w.raw,sum_bytes(w));return 0;}
