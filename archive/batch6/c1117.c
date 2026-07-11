#include <stdio.h>
struct Nibble{unsigned low:4;unsigned high:4;};
static unsigned combine(struct Nibble n){return n.low|(n.high<<4);}
int main(void){struct Nibble n={10,12};printf("c1117 nibble=%u\n",combine(n));return 0;}
