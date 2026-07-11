#include <stdio.h>
static int power(int base,int exponent){int r=1;while(exponent){if(exponent%2)r=r*base%1000;base=base*base%1000;exponent/=2;}return r;}
int main(void){printf("c8910 modpow=%d\n",power(7,23));return 0;}
