#include <stdio.h>
static int cobs_encode(const unsigned char *in,int count,unsigned char *out,int cap){int read=0,write=1,code_at=0;unsigned char code=1;if(cap<2)return -1;while(read<count){if(in[read]==0){out[code_at]=code;code=1;code_at=write++;}else{if(write>=cap)return -1;out[write++]=in[read];++code;}++read;}out[code_at]=code;return write;}
int main(void){unsigned char in[5]={1,2,0,3,4},out[8];int n=cobs_encode(in,5,out,8);printf("c8931 cobs=%d,%u,%u\n",n,(unsigned)out[0],(unsigned)out[3]);return !(n==6&&out[0]==3&&out[3]==3);}
