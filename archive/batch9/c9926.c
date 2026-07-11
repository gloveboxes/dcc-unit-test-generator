#include <stdio.h>
#include <stdint.h>
static uint32_t rotate_left(uint32_t value,unsigned amount){amount&=31U;return (uint32_t)((value<<amount)|(value>>(32U-amount)));}
int main(void){uint32_t value=rotate_left((uint32_t)0x12345678UL,8U);printf("c9926 rotate=%08lX\n",(unsigned long)value);return value!=(uint32_t)0x34567812UL;}
