#include <stdio.h>
static void trim_left(char* d,const char* s){while(*s==' ')++s;while((*d++=*s++));}
int main(void){char b[10];trim_left(b,"  cat");printf("c8929 ltrim=%s\n",b);return 0;}
