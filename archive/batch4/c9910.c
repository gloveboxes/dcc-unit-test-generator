#include <stdio.h>
static int parse_pair(const char *text,int *left,int *right){int i=0;*left=0;*right=0;while(text[i]>='0'&&text[i]<='9')*left=*left*10+text[i++]-'0';if(text[i++]!=',')return 0;while(text[i]>='0'&&text[i]<='9')*right=*right*10+text[i++]-'0';return text[i]=='\0';}
int main(void){int a,b,ok;ok=parse_pair("12,34",&a,&b);printf("c9910 pair=%d/%d,%d\n",ok,a,b);return 0;}
