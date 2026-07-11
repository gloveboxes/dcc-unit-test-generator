#include <stdio.h>
#include <stdint.h>

static inline int16_t lerp(int16_t a,int16_t b,uint8_t fraction){int32_t delta=(int32_t)(b-a)*fraction;return (int16_t)(a+delta/255);}
int main(void){int16_t a=lerp(-100,300,64),b=lerp(200,600,192),c=lerp(50,50,127);printf("c9917 interpolate=%d,%d,%d\n",(int)a,(int)b,(int)c);return !(a==0&&b==501&&c==50);}
