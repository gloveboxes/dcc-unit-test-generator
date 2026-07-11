#include <stdio.h>
static int wildcard(const char *pattern,const char *text){const char *star=0,*retry=0;while(*text){if(*pattern=='?'||*pattern==*text){++pattern;++text;}else if(*pattern=='*'){star=pattern++;retry=text;}else if(star){pattern=star+1;text=++retry;}else return 0;}while(*pattern=='*')++pattern;return *pattern=='\0';}
int main(void){int a=wildcard("C*?.COM","CPM2.COM"),b=wildcard("A?.COM","ABC.COM");printf("c8910 wildcard=%d,%d\n",a,b);return !(a&&!b);}
