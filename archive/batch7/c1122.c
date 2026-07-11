#include <stdio.h>
struct Doublet{union{unsigned short w;struct{unsigned char v[2];};};};
int main(void){struct Doublet d={{0x1122}};printf("c1122 doub=%02x\n",d.v[0]);return 0;}
