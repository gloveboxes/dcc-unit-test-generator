#include <stdio.h>
#include <stdint.h>
static int encode(uint16_t value,char *out){char digits[]="0123456789ABCDEF";char temp[8];int count=0,i;do{temp[count++]=digits[value%16];value/=16;}while(value);for(i=0;i<count;++i)out[i]=temp[count-i-1];out[count]='\0';return count;}
int main(void){char text[8];int count=count=encode(48879,text);printf("c9914 hex=%d/%s\n",count,text);return 0;}
