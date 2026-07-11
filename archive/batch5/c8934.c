#include <stdio.h>
static int bitcount(unsigned v){int r=0;while(v){v&=v-1;++r;}return r;}
int main(void){printf("c8934 bits=%d,%d\n",bitcount(0xF0),bitcount(0xAA));return 0;}
