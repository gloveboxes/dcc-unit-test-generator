#include <stdio.h>
static int power_mod(int base,int exponent,int modulus){int result=1;while(exponent){if(exponent&1)result=result*base%modulus;base=base*base%modulus;exponent>>=1;}return result;}
int main(void){printf("c8915 modpow=%d,%d\n",power_mod(3,13,17),power_mod(7,8,19));return 0;}
