#include <stdio.h>
static int hamming(unsigned a,unsigned b){unsigned v=a^b;int r=0;while(v){v&=v-1;++r;}return r;}
int main(void){printf("c8920 hamming=%d,%d\n",hamming(0xAA,0x55),hamming(0xF0,0xF1));return 0;}
