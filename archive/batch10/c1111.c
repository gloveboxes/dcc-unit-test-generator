#include <stdio.h>
#include <stdint.h>

/* The word overlay assumes little-endian layout, shared by Z80 and the host. */
union Diagnostic { uint16_t word; struct { unsigned code:8;unsigned subsystem:4;unsigned severity:3;unsigned active:1; }; };
static int priority(union Diagnostic d){return (int)d.severity*10+(int)d.subsystem+(d.active?100:0);}
int main(void){union Diagnostic d={.code=0x2A,.subsystem=5,.severity=3,.active=1};printf("c1111 diagnostic=%d,%u,%04x\n",priority(d),(unsigned)d.code,(unsigned)d.word);return !(priority(d)==135&&d.code==42U&&d.word==0xB52AU);}
