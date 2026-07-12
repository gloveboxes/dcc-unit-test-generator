#include <stdio.h>
#include <stdint.h>
struct Register{union{uint16_t word;struct{uint8_t low;uint8_t high;};};};
int main(void){struct Register r;r.word=0x1234;printf("c1108 register=%X/%X\n",(unsigned)r.low,(unsigned)r.high);return 0;}
