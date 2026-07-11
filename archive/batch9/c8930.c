#include <stdio.h>
static int parity16(unsigned int value){value^=value>>8;value^=value>>4;value^=value>>2;value^=value>>1;return value&1U;}
int main(void){int a=parity16(0x000FU),b=parity16(0x0007U);printf("c8930 parity=%d,%d\n",a,b);return !(a==0&&b==1);}
