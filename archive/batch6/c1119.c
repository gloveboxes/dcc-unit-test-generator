#include <stdio.h>
struct Address{unsigned bank:3;unsigned offset:13;};
static unsigned linear(struct Address a){return (a.bank<<13)|a.offset;}
int main(void){struct Address a={3,4095};printf("c1119 address=%u\n",linear(a));return 0;}
