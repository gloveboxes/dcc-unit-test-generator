#include <stdio.h>
static unsigned ungray(unsigned g){unsigned n=0;while(g){n^=g;g>>=1;}return n;}
int main(void){printf("c8922 ungray=%u,%u\n",ungray(4),ungray(10));return 0;}
