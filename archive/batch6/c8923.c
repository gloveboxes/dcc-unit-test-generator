#include <stdio.h>
static int bit_reverse(unsigned v){unsigned r=0;int i;for(i=0;i<8;++i){r=(r<<1)|(v&1);v>>=1;}return r;}
int main(void){printf("c8923 bitrev=%d,%d\n",bit_reverse(1),bit_reverse(0xA5));return 0;}
