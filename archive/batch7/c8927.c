#include <stdio.h>
static void my_memset(void* p,int v,int n){char* d=(char*)p;while(n--)*d++=(char)v;}
int main(void){char b[4];my_memset(b,0x42,4);printf("c8927 mem=%02x,%02x\n",b[0],b[3]);return 0;}
