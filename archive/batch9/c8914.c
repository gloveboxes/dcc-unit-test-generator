#include <stdio.h>
static unsigned int isqrt(unsigned int value){unsigned int guess=value?value:1,next;do{next=(guess+value/guess)/2;if(next>=guess)return guess;guess=next;}while(1);}
int main(void){unsigned int a=isqrt(1000U),b=isqrt(1024U);printf("c8914 isqrt=%u,%u\n",a,b);return !(a==31U&&b==32U);}
