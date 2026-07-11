#include <stdio.h>
struct Address{union{unsigned long value;struct{unsigned char a;unsigned char b;unsigned char c;unsigned char d;};};};
int main(void){struct Address ip;ip.a=10;ip.b=20;ip.c=30;ip.d=40;printf("c1111 address=%u.%u.%u.%u\n",ip.a,ip.b,ip.c,ip.d);return 0;}
