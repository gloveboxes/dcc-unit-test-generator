#include <stdio.h>
static int encode_runs(const char *text,char out[][2],int cap){int used=0;while(*text){char value=*text;int count=0;while(*text==value&&count<9){++text;++count;}if(used==cap)return -1;out[used][0]=value;out[used][1]=(char)('0'+count);++used;}return used;}
int main(void){char out[6][2];int n=encode_runs("AAABBCCCCD",out,6);printf("c9920 runs=%d,%c%c\n",n,out[2][0],out[2][1]);return !(n==4&&out[2][0]=='C'&&out[2][1]=='4');}
