#include <stdio.h>
#include <stdint.h>
enum Op { OP_LOAD, OP_ADD, OP_STORE, OP_COUNT };
struct Spec { uint8_t bytes; int cycles; };
static const struct Spec specs[OP_COUNT] = {[OP_STORE]={2,4},[OP_LOAD]={2,3},[OP_ADD]={1,2}};
int main(void){int total=0;for(int op=0;op<OP_COUNT;++op)total+=specs[op].cycles;printf("c9901 opcodes=%d,%u\n",total,(unsigned)specs[OP_STORE].bytes);return !(total==9&&specs[OP_STORE].bytes==2);}
