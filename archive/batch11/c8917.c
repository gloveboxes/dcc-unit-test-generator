#include <stdio.h>
static int rle_decode(const char *src,char *dst,int cap){int n=0;while(src[0]&&src[1]){int count=src[0]-'0';char ch=src[1];int i;for(i=0;i<count;++i){if(n+1>=cap)return -1;dst[n++]=ch;}src+=2;}dst[n]='\0';return n;}
int main(void){char out[16];int n=rle_decode("3A2B4C",out,16);printf("c8917 rle=%d,%s\n",n,out);return !(n==9&&out[0]=='A'&&out[3]=='B'&&out[5]=='C');}
