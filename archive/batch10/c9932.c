#include <stdio.h>
#include <stdint.h>

static uint32_t fingerprint(const uint8_t *data,int n){uint32_t h=2166136261UL;for(int i=0;i<n;++i){h^=data[i];h*=16777619UL;}return h;}
int main(void){uint8_t data[7]={'C','P','M','-','Z','8','0'};uint32_t a=fingerprint(data,7);data[3]='2';uint32_t b=fingerprint(data,7);printf("c9932 fingerprint=%08lX,%d\n",(unsigned long)a,a!=b);return !(a==0x597FA4D2UL&&a!=b);}
