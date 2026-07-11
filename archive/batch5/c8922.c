#include <stdio.h>
static int modpow(int b,int e,int m){int r=1;while(e){if(e&1)r=r*b%m;b=b*b%m;e>>=1;}return r;}
int main(void){printf("c8922 modpow=%d,%d\n",modpow(3,7,20),modpow(5,5,17));return 0;}
