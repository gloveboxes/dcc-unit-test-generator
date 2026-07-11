#include <stdio.h>
struct Register{union{unsigned word;struct{unsigned low;unsigned high;};};};
int main(void){struct Register r;r.word=0x1234;printf("c1108 register=%X/%X\n",r.low,r.high);return 0;}
