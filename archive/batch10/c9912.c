#include <stdio.h>
#include <stdint.h>

static void threshold(int n,const uint8_t *restrict in,uint8_t *restrict mask,uint8_t level){for(int i=0;i<n;++i)mask[i]=in[i]>=level?1U:0U;}
int main(void){uint8_t input[9]={4,9,2,8,7,1,6,3,5},mask[9];threshold(9,input,mask,6);int count=0,code=0;for(int i=0;i<9;++i){count+=mask[i];code=code*2+mask[i];}printf("c9912 threshold=%d,%d\n",count,code);return !(count==4&&code==180);}
