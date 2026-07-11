#include <stdio.h>
#include <stdint.h>
static void mix(int count,const int16_t *restrict a,const int16_t *restrict b,int16_t *restrict out){for(int i=0;i<count;++i)out[i]=(int16_t)((a[i]+b[i])/2);}
int main(void){int16_t a[4]={100,200,-100,50},b[4]={20,40,20,-10},out[4];mix(4,a,b,out);printf("c9904 mix=%d,%d\n",(int)out[0],(int)out[2]);return !(out[0]==60&&out[2]==-40);}
