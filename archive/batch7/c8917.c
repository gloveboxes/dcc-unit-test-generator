#include <stdio.h>
static int parse_int(const char* s){int r=0,neg=0;if(*s=='-'){neg=1;++s;}while(*s)r=r*10+(*s++-'0');return neg?-r:r;}
int main(void){printf("c8917 parse=%d,%d\n",parse_int("123"),parse_int("-45"));return 0;}
