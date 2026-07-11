#include <stdio.h>
static int luhn(const char *s){int i,sum,d,alt;sum=0;alt=0;for(i=8;i>=0;--i){d=s[i]-'0';if(alt){d*=2;if(d>9)d-=9;}sum+=d;alt=!alt;}return sum%10==0;}
int main(void){printf("c8903 luhn=%d,%d\n",luhn("799273987"),luhn("799273988"));return 0;}
