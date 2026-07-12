#include <stdio.h>
static long power(long base,int exponent){long r=1;while(exponent){if(exponent%2)r=r*base%1000L;base=base*base%1000L;exponent/=2;}return r;}
int main(void){printf("c8910 modpow=%ld\n",power(7L,23));return 0;}
