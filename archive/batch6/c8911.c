#include <stdio.h>
static int hex(char c){return c<='9'?c-'0':c-'A'+10;}
static unsigned short parse(const char *s){int i;unsigned short r=0;for(i=0;s[i];++i)r=(unsigned short)(r*16+hex(s[i]));return r;}
int main(void){printf("c8911 hex=%u,%u\n",(unsigned)parse("2A"),(unsigned)parse("BEEF"));return 0;}
