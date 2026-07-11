#include <stdio.h>
#include <stdint.h>

static int format_mac(char *out,const uint8_t address[6]){return sprintf(out,"%02X:%02X:%02X:%02X:%02X:%02X",(unsigned)address[0],(unsigned)address[1],(unsigned)address[2],(unsigned)address[3],(unsigned)address[4],(unsigned)address[5]);}
int main(void){uint8_t address[6]={0x02,0x10,0x20,0x30,0x40,0xFE};char text[18];int n=format_mac(text,address);printf("c9921 mac=%d,%s\n",n,text);return !(n==17&&text[0]=='0'&&text[16]=='E');}
