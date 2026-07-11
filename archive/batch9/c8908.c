#include <stdio.h>
static int isbn10(const char *text){int sum=0,i,digit;for(i=0;i<10;++i){digit=text[i]=='X'?10:text[i]-'0';if(digit<0||digit>10)return 0;sum+=(10-i)*digit;}return text[10]=='\0'&&sum%11==0;}
int main(void){int a=isbn10("0306406152"),b=isbn10("0306406153");printf("c8908 isbn=%d,%d\n",a,b);return !(a&&!b);}
