#include <stdio.h>
static unsigned short hash16(const char* s){unsigned short h=0x811c;while(*s){h^=(unsigned char)*s++;h=(unsigned short)(h*0x0101);}return h;}
int main(void){printf("c8924 hash=%u,%u\n",(unsigned)hash16("abc"),(unsigned)hash16("xyz"));return 0;}
