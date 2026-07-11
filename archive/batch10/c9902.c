#include <stdio.h>
#include <stdbool.h>

enum Command { READ, WRITE, VERIFY, ERASE, COMMANDS };
struct Spec { unsigned char bytes; bool mutates; int cycles; };
static const struct Spec specs[COMMANDS]={[ERASE]={.bytes=1,.mutates=true,.cycles=9},[READ]={.bytes=3,.mutates=false,.cycles=2},[VERIFY]={.bytes=2,.mutates=false,.cycles=5},[WRITE]={.bytes=4,.mutates=true,.cycles=6}};
int main(void){int cycles=0,mutating=0;for(int i=0;i<COMMANDS;++i){cycles+=specs[i].cycles;mutating+=specs[i].mutates;}printf("c9902 commands=%d,%d,%u\n",cycles,mutating,(unsigned)specs[WRITE].bytes);return !(cycles==22&&mutating==2&&specs[WRITE].bytes==4);}
