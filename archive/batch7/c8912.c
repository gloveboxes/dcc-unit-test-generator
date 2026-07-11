#include <stdio.h>
static int octal(const char* s){int r=0;while(*s)r=r*8+(*s++-'0');return r;}
int main(void){printf("c8912 oct=%d,%d\n",octal("75"),octal("10"));return 0;}
