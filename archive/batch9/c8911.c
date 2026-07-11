#include <stdio.h>
static int replace_all(const char *src,char from,char to,char *dst,int cap){int n=0;while(*src){if(n+1>=cap)return -1;dst[n++]=*src==from?to:*src;++src;}dst[n]='\0';return n;}
int main(void){char out[12];int n=replace_all("A-B-C",'-','/',out,12);printf("c8911 replace=%d,%s\n",n,out);return !(n==5&&out[1]=='/'&&out[3]=='/');}
