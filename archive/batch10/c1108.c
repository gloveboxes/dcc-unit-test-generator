#include <stdio.h>
#include <stdint.h>

struct Inode { uint16_t mode; union { struct { uint16_t firstBlock,blockCount; }; struct { uint16_t start,count; }; }; uint32_t size; };
static int valid(const struct Inode *n){return n->count>0U&&n->size<=(uint32_t)n->count*128U&&(n->mode&0x8000U)!=0U;}
int main(void){struct Inode n={.mode=0x81A4U,.firstBlock=12,.blockCount=3,.size=350U};printf("c1108 inode=%d,%u,%lu\n",valid(&n),(unsigned)n.start,(unsigned long)n.size);return !(valid(&n)&&n.start==12U&&n.size==350U);}
