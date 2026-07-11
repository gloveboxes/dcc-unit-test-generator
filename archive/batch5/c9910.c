#include <stdio.h>
static int parse(const char *s,int *out){int i=0,v=0;if(!s[0])return 0;while(s[i]>='0'&&s[i]<='9')v=v*10+s[i++]-'0';if(s[i])return 0;*out=v;return 1;}
int main(void){int a,b,ok1,ok2;ok1=parse("2048",&a);ok2=parse("20x",&b);printf("c9910 parse=%d,%d/%d\n",ok1,a,ok2);return 0;}
