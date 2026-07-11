#include <stdio.h>
struct ByteSplit{union{unsigned short s;struct{unsigned char l;unsigned char h;};};};
int main(void){struct ByteSplit bs;bs.s=0x1234;printf("c1104 split=%x,%x\n",bs.l,bs.h);return 0;}
