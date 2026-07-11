#include <stdio.h>
#include <stdint.h>
static inline uint8_t saturating_add(uint8_t a,uint8_t b){unsigned sum=(unsigned)a+b;return (uint8_t)(sum>255U?255U:sum);}
int main(void){uint8_t a=saturating_add(200,80),b=saturating_add(20,30);printf("c9910 saturate=%u,%u\n",(unsigned)a,(unsigned)b);return !(a==255&&b==50);}
