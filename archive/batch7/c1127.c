#include <stdio.h>
struct PairWord{union{unsigned short s;struct{unsigned char a;unsigned char b;};};};
int main(void){struct PairWord pw;pw.a=0x42;pw.b=0x24;printf("c1127 pw=%04x\n",pw.s);return 0;}
