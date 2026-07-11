#include <stdio.h>
static int hex(char c){return c<='9'?c-'0':c-'A'+10;}
static int parse(const char *s){int i,r=0;for(i=0;s[i];++i)r=r*16+hex(s[i]);return r;}
int main(void){printf("c8911 hex=%d,%d\n",parse("2A"),parse("BEEF"));return 0;}
