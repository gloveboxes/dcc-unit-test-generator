#include <stdio.h>
#include <stdint.h>

static int fixed(char *out,int32_t milli){long whole=(long)(milli/1000);int fraction=(int)(milli%1000);if(fraction<0)fraction=-fraction;return sprintf(out,"%ld.%03d",whole,fraction);}
int main(void){char a[16],b[16];int na=fixed(a,12345),nb=fixed(b,-7089);printf("c9922 decimal=%d,%s,%d,%s\n",na,a,nb,b);return !(na==6&&nb==6&&a[2]=='.'&&b[0]=='-');}
