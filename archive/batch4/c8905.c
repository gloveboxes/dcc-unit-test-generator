#include <stdio.h>
static int parity(unsigned value){int bit=0;while(value){bit^=value&1;value>>=1;}return bit;}
int main(void){printf("c8905 parity=%d,%d,%d\n",parity(0),parity(7),parity(0xA5));return 0;}
