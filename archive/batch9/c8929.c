#include <stdio.h>
static void put_u16le(unsigned char out[2],unsigned int value){out[0]=(unsigned char)value;out[1]=(unsigned char)(value>>8);}
static unsigned int get_u16le(const unsigned char in[2]){return (unsigned int)(in[0]|((unsigned int)in[1]<<8));}
int main(void){unsigned char data[2];unsigned int actual;put_u16le(data,0xBEEF);actual=get_u16le(data);printf("c8929 pack=%04x\n",actual);return actual!=0xBEEF;}
