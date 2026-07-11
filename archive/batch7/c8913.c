#include <stdio.h>
static int binary(const char* s){int r=0;while(*s)r=r*2+(*s++-'0');return r;}
int main(void){printf("c8913 bin=%d,%d\n",binary("1010"),binary("11111111"));return 0;}
