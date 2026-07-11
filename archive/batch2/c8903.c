#include <stdio.h>
static int adler(const unsigned char *s){int a=1,b=0;while(*s){a=(a+*s++)%65521;b=(b+a)%65521;}return b*65536+a;}
int main(void){long value=adler((const unsigned char *)"portable");printf("c8903 adler=%ld\n",value);return 0;}
