#include <stdio.h>
struct Address{union{unsigned long value;struct{unsigned char a;unsigned char b;unsigned char c;unsigned char d;};};};
int main(void){struct Address a={.a=10,.b=20,.c=30,.d=40};printf("c1110 address=%u.%u.%u.%u\n",a.a,a.b,a.c,a.d);return 0;}
