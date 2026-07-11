#include <stdio.h>
#include <stdint.h>

enum BackupKind { FULL,INCREMENTAL };struct Backup { int generation;enum BackupKind kind;union { struct { uint16_t files,blocks; };struct { uint16_t changed,base; }; }; };
static unsigned work(const struct Backup *b){return b->kind==FULL?(unsigned)b->files+b->blocks:(unsigned)b->changed*2U+b->base;}
int main(void){struct Backup set[3]={{.generation=1,.kind=FULL,.files=30,.blocks=80},{.generation=2,.kind=INCREMENTAL,.changed=7,.base=1},{.generation=3,.kind=INCREMENTAL,.changed=4,.base=2}};unsigned total=0;for(int i=0;i<3;++i)total+=work(&set[i]);printf("c1130 backups=%u,%u\n",total,(unsigned)set[1].base);return !(total==135U&&set[1].base==1U);}
