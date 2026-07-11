#include <stdio.h>
int main(void){const char *s="{[()()]}";char stack[16];int top=0,i,ok=1;for(i=0;s[i];++i){if(s[i]=='('||s[i]=='['||s[i]=='{')stack[top++]=s[i];else if(top==0||(s[i]==')'&&stack[top-1]!='(')||(s[i]==']'&&stack[top-1]!='[')||(s[i]=='}'&&stack[top-1]!='{'))ok=0;else --top;}printf("c8904 brackets=%d\n",ok&&top==0);return 0;}
