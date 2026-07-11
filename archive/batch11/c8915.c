#include <stdio.h>
static int luhn(const char *text){int sum=0,odd=1,i;for(i=0;text[i];++i);--i;while(i>=0){int d=text[i]-'0';if(!odd){d*=2;if(d>9)d-=9;}sum+=d;odd=!odd;--i;}return sum%10==0;}
int main(void){int a=luhn("4532015112830366"),b=luhn("4532015112830367");printf("c8915 luhn=%d,%d\n",a,b);return !(a&&!b);}
