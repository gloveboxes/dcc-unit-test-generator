#include <stdio.h>
#include <stdint.h>

static void fir(int n,const int16_t *restrict in,int16_t *restrict out){static const int16_t tap[3]={1,2,1};for(int i=0;i<n;++i){int32_t sum=0;for(int k=0;k<3;++k)if(i>=k)sum+=(int32_t)in[i-k]*tap[k];out[i]=(int16_t)(sum/4);}}
int main(void){int16_t in[6]={4,8,12,16,20,24},out[6];fir(6,in,out);int sum=0;for(int i=0;i<6;++i)sum+=out[i];printf("c9910 fir=%d,%d,%d\n",(int)out[1],(int)out[5],sum);return !(out[1]==4&&out[5]==20&&sum==61);}
