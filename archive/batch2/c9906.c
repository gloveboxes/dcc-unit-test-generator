#include <stdint.h>
#include <stdio.h>
int main(void){int32_t a=(int32_t)123456,b=(int32_t)-23456;uint16_t mask=(uint16_t)0x0F0F;printf("c9906 fixed=%ld/%u\n",(long)(a+b),(unsigned)mask);return 0;}
