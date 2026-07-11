#include <stdio.h>
static int balance(const char *s){int depth=0,i;for(i=0;s[i]!='\0';++i){if(s[i]=='(')++depth;else if(s[i]==')'&&--depth<0)return 0;}return depth==0;}
int main(void){printf("c8906 parens=%d,%d\n",balance("(()())"),balance("())("));return 0;}
