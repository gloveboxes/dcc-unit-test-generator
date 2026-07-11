#include <stdio.h>
struct Frame{unsigned start:1;unsigned end:1;unsigned kind:6;union{int payload;struct{int address;int count;};};};
int main(void){struct Frame f={1,0,12,{.address=100,.count=4}};printf("c1131 frame=%u,%d,%d\n",f.kind,f.address,f.count);return 0;}
