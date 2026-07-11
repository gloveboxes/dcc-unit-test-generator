#include <stdio.h>
static void my_memcpy(void* d,const void* s,int n){char* dd=(char*)d;const char* ss=(const char*)s;while(n--)*dd++=*ss++;}
int main(void){char a[]="ABCD",b[5];my_memcpy(b,a,5);printf("c8928 set=%s\n",b);return 0;}
