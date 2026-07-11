#include <stdio.h>
static int pack(int hi,int lo){return (hi<<8)|lo;}
int main(void){printf("c9929 pack=%d,%d\n",pack(0x12,0x34),pack(0xAB,0xCD));return 0;}
