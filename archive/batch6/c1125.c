#include <stdio.h>
struct Header{unsigned ack:1;unsigned sequence:7;unsigned length:8;};
static int next_sequence(struct Header h){return (h.sequence+1)&127;}
int main(void){struct Header h={1,126,40};printf("c1125 sequence=%d,%u\n",next_sequence(h),h.length);return 0;}
