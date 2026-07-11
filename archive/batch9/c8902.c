#include <stdio.h>
static int balanced(const char *text){char stack[16];int top=0;char open;while(*text){if(*text=='('||*text=='['||*text=='{')stack[top++]=*text;else if(*text==')'||*text==']'||*text=='}'){if(top==0)return 0;open=stack[--top];if((open=='('&&*text!=')')||(open=='['&&*text!=']')||(open=='{'&&*text!='}'))return 0;}++text;}return top==0;}
int main(void){int a=balanced("{a+[b*(c)]}"),b=balanced("([)]");printf("c8902 brackets=%d,%d\n",a,b);return !(a&&!b);}
