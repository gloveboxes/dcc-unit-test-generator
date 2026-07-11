#include <stdio.h>
struct Address{union{unsigned long value;struct{unsigned char a;unsigned char b;unsigned char c;unsigned char d;};};};
int main(void){struct Address address;address.a=10;address.b=20;address.c=30;address.d=40;printf("c1108 address=%u.%u.%u.%u\n",address.a,address.b,address.c,address.d);return 0;}
