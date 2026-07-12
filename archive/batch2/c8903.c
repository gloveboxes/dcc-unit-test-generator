#include <stdio.h>
static long adler(const unsigned char *s){long a=1,b=0;while(*s){a=(a+*s++)%65521;b=(b+a)%65521;}return b*65536L+a;}
int main(void){long value=adler((const unsigned char *)"portable");printf("c8903 adler=%ld\n",value);return 0;}
