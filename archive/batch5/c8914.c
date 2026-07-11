#include <stdio.h>
static int words(const char *s){int in=0,r=0,i;for(i=0;s[i];++i){if(s[i]!=' '&&!in){++r;in=1;}if(s[i]==' ')in=0;}return r;}
int main(void){printf("c8914 words=%d,%d\n",words("one two three"),words("  CP/M  Z80"));return 0;}
