#include <stdio.h>
static int hash16(const char* s){unsigned int h=0x811c;while(*s){h^=(unsigned char)*s++;h*=0x0101;}return h&0xffff;}
int main(void){printf("c8924 hash=%d,%d\n",hash16("abc"),hash16("xyz"));return 0;}
