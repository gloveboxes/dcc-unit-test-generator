#include <stdio.h>
static int eval(const char *s){int st[8],top=0,a,b,i;for(i=0;s[i];++i)if(s[i]>='0'&&s[i]<='9')st[top++]=s[i]-'0';else{b=st[--top];a=st[--top];st[top++]=s[i]=='+'?a+b:s[i]=='-'?a-b:a*b;}return st[0];}
int main(void){printf("c8925 rpn=%d\n",eval("23+45-*"));return 0;}
