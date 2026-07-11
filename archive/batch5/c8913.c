#include <stdio.h>
static int hex(char c){if(c>='0'&&c<='9')return c-'0';if(c>='A'&&c<='F')return c-'A'+10;return -1;}
static int parse(const char *s){int i,v=0,d;for(i=0;s[i];++i){d=hex(s[i]);if(d<0)return -1;v=v*16+d;}return v;}
int main(void){printf("c8913 hex=%d,%d\n",parse("1A3"),parse("F0"));return 0;}
