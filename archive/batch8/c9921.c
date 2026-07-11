#include <stdio.h>
static void hex_byte(unsigned char value, char output[3]) { static const char digits[]="0123456789ABCDEF"; output[0]=digits[value>>4]; output[1]=digits[value&15]; output[2]='\0'; }
int main(void) { char output[3]; hex_byte(0xAF,output); printf("c9921 hex=%s\n",output); return !(output[0]=='A' && output[1]=='F'); }
