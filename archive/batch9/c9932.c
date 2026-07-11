#include <stdio.h>
#include <stdint.h>
static inline int16_t q8_multiply(int16_t a,int16_t b){int32_t product=(int32_t)a*b;return (int16_t)(product/256);}
int main(void){int16_t a=(int16_t)(3*256/2),b=2*256,value=q8_multiply(a,b);printf("c9932 fixed=%d.%02d\n",(int)(value/256),(int)((value%256)*100/256));return value!=3*256;}
