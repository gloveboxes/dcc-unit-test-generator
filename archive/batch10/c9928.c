#include <stdio.h>
#include <stdint.h>

static void covariance(int n,const int16_t *restrict x,const int16_t *restrict y,int32_t *restrict xx,int32_t *restrict xy){int32_t sx=0,sy=0,sxx=0,sxy=0;for(int i=0;i<n;++i){sx+=x[i];sy+=y[i];sxx+=(int32_t)x[i]*x[i];sxy+=(int32_t)x[i]*y[i];}*xx=n*sxx-sx*sx;*xy=n*sxy-sx*sy;}
int main(void){int16_t x[5]={1,2,4,5,8},y[5]={3,1,6,7,9};int32_t xx,xy;covariance(5,x,y,&xx,&xy);printf("c9928 covariance=%ld,%ld\n",(long)xx,(long)xy);return !(xx==150&&xy==160);}
