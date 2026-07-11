#include <stdio.h>
enum StorageKind { STORAGE_BLOCK,STORAGE_STREAM };
struct Storage { enum StorageKind kind; union { struct { int blocks,block_size; }; struct { int bytes,position; }; }; };
static long capacity(const struct Storage *s){return s->kind==STORAGE_BLOCK?(long)s->blocks*s->block_size:s->bytes;}
int main(void){struct Storage s={STORAGE_BLOCK,{.blocks=16,.block_size=128}};long actual=capacity(&s);printf("c1130 storage=%ld\n",actual);return actual!=2048L;}
