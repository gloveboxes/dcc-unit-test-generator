#include <stdio.h>
#include <stdint.h>

struct Frame { unsigned id:11; unsigned remote:1; unsigned extended:1; unsigned length:3; };
static unsigned cost(struct Frame f){return 47U+f.length*10U+(f.remote?0U:8U);}
int main(void){struct Frame frames[3]={{.id=0x120,.length=4},{.id=0x321,.remote=1,.length=0},{.id=0x42,.extended=1,.length=7}};unsigned total=0;for(int i=0;i<3;++i)total+=cost(frames[i]);printf("c9923 busframes=%u,%u\n",total,frames[1].id);return !(total==267U&&frames[1].id==0x321U);}
