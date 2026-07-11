#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static bool one_bit(uint16_t a,uint16_t b){uint16_t x=(uint16_t)(a^b);return x!=0U&&(x&(uint16_t)(x-1U))==0U;}
static int transitions(const uint16_t *sequence,int n){int valid=0;for(int i=1;i<n;++i)valid+=one_bit(sequence[i-1],sequence[i]);return valid;}
int main(void){uint16_t values[8]={0,1,3,2,6,7,5,4};int n=transitions(values,8);values[6]=0;int broken=transitions(values,8);printf("c9931 gray=%d,%d\n",n,broken);return !(n==7&&broken==6);}
