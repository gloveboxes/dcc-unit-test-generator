#include <stdio.h>
#include <stdbool.h>
static bool identifier(const char *text){if(!((*text>='A'&&*text<='Z')||(*text>='a'&&*text<='z')||*text=='_'))return false;for(++text;*text;++text)if(!((*text>='A'&&*text<='Z')||(*text>='a'&&*text<='z')||(*text>='0'&&*text<='9')||*text=='_'))return false;return true;}
int main(void){bool a=identifier("port_2"),b=identifier("2port");printf("c9905 ident=%d,%d\n",(int)a,(int)b);return !(a&&!b);}
