#include <stdio.h>
#include <stdint.h>
static uint16_t rotate_left(uint16_t value,unsigned count) { count&=15U; return (uint16_t)((value<<count)|(value>>(16U-count))); }
int main(void) { uint16_t actual=rotate_left(0x1234U,4); printf("c9924 rotate=%04X\n",(unsigned)actual); return actual!=0x2341U; }
