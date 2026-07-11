#include <stdio.h>
static int encode_pair(int hi,int lo){return (hi<<8)|lo;}
int main(void){printf("c9922 pair=%d,%d\n",encode_pair(0x12,0x34),encode_pair(0xAB,0xCD));return 0;}
