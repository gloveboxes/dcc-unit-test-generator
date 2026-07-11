#include <stdio.h>
struct Flags { union { unsigned char raw; struct { unsigned readable:1; unsigned writable:1; unsigned executable:1; unsigned :5; }; }; };
int main(void){struct Flags f;f.raw=0;f.readable=1;f.executable=1;printf("c1123 flags=%02x\n",f.raw);return f.raw!=5;}
