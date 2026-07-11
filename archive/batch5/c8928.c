#include <stdio.h>
static int valid(const char *s){int d=0,i;for(i=0;s[i];++i){if(s[i]=='(')++d;else if(s[i]==')'&&--d<0)return 0;}return d==0;}
int main(void){printf("c8928 parens=%d,%d\n",valid("(()())"),valid("())("));return 0;}
