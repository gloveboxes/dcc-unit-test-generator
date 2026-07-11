#include <stdio.h>
static int roman_value(char c){return c=='I'?1:c=='V'?5:c=='X'?10:c=='L'?50:c=='C'?100:c=='D'?500:c=='M'?1000:0;}
static int from_roman(const char *text){int total=0,i=0;while(text[i]){int cur=roman_value(text[i]),next=text[i+1]?roman_value(text[i+1]):0;total+=cur<next?-cur:cur;++i;}return total;}
int main(void){int a=from_roman("MCMXCIV"),b=from_roman("XLII");printf("c8901 roman=%d,%d\n",a,b);return !(a==1994&&b==42);}
