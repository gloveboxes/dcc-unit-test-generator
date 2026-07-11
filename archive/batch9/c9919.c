#include <stdio.h>
#include <stdint.h>
static inline uint16_t swap16(uint16_t value){return (uint16_t)((value>>8)|(value<<8));}
int main(void){uint16_t a=swap16(0x1234U),b=swap16(a);printf("c9919 swap=%04x,%04x\n",(unsigned)a,(unsigned)b);return !(a==0x3412U&&b==0x1234U);}
