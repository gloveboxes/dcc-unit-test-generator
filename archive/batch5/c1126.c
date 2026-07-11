#include <stdio.h>
struct Register{struct{unsigned low:8;unsigned high:8;};};
int main(void){struct Register r={.low=0x34,.high=0x12};printf("c1126 register=%u,%u\n",r.low,r.high);return 0;}
