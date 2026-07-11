#include <stdio.h>
static int ends_with(const char* s,const char* suf){int sn=0,en=0;while(s[sn])++sn;while(suf[en])++en;if(en>sn)return 0;while(en>0)if(s[--sn]!=suf[--en])return 0;return 1;}
int main(void){printf("c8915 ends=%d,%d\n",ends_with("hello","lo"),ends_with("hello","hi"));return 0;}
