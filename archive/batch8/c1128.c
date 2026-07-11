#include <stdio.h>
struct Protocol { union { unsigned short raw; struct { unsigned version:3; unsigned kind:5; unsigned length:8; }; }; };
int main(void){struct Protocol p;p.raw=0;p.version=2;p.kind=17;p.length=64;printf("c1128 protocol=%u,%u,%u\n",p.version,p.kind,p.length);return !(p.version==2&&p.kind==17&&p.length==64);}
