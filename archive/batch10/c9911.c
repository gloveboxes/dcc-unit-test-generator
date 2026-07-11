#include <stdio.h>
#include <stdint.h>

static void interleave(int n,const uint8_t *restrict left,const uint8_t *restrict right,uint8_t *restrict out){for(int i=0;i<n;++i){out[i*2]=left[i];out[i*2+1]=right[i];}}
int main(void){uint8_t left[4]={1,3,5,7},right[4]={2,4,6,8},out[8];interleave(4,left,right,out);uint32_t signature=0;for(int i=0;i<8;++i)signature=signature*9U+out[i];printf("c9911 interleave=%u,%u,%lu\n",(unsigned)out[1],(unsigned)out[6],(unsigned long)signature);return !(out[1]==2&&out[6]==7&&signature==6053444UL);}
