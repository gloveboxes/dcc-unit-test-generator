#include <stdio.h>
struct Address { union { struct { unsigned char a,b,c,d; }; unsigned char octet[4]; }; };
static int private_address(const struct Address *p){return p->a==10||(p->a==192&&p->b==168);}
int main(void){struct Address p={{.a=192,.b=168,.c=1,.d=20}};int actual=private_address(&p);printf("c1110 address=%d,%u\n",actual,(unsigned)p.octet[3]);return !(actual&&p.d==20);}
