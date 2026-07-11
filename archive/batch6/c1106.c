#include <stdio.h>
struct Register{union{unsigned short value;struct{unsigned char low;unsigned char high;};};};
int main(void){struct Register r;r.low=0x34;r.high=0x12;printf("c1106 reg=%u,%u,%u\n",r.value,r.low,r.high);return 0;}
