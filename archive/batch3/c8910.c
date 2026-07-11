#include <stdio.h>
static int eval(const char *s){int stack[8],top,a,b,i;top=0;for(i=0;s[i]!='\0';++i){if(s[i]>='0'&&s[i]<='9')stack[top++]=s[i]-'0';else{b=stack[--top];a=stack[--top];if(s[i]=='+')stack[top++]=a+b;else if(s[i]=='-')stack[top++]=a-b;else stack[top++]=a*b;}}return stack[0];}
int main(void){printf("c8910 postfix=%d\n",eval("23+45-*"));return 0;}
