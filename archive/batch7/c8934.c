#include <stdio.h>
static int count_bits(unsigned int v){int r=0;while(v){if(v&1)++r;v>>=1;}return r;}
int main(void){printf("c8934 bits=%d,%d\n",count_bits(0x55),count_bits(0x0f));return 0;}
