#include <stdio.h>
static int parity(unsigned v){int r=0;while(v){r^=v&1;v>>=1;}return r;}
int main(void){printf("c8917 parity=%d,%d,%d\n",parity(0),parity(7),parity(255));return 0;}
