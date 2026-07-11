#include <stdio.h>
struct Handle { union { struct { unsigned char index,generation; }; unsigned short raw; }; };
static int same_slot(const struct Handle *a,const struct Handle *b){return a->index==b->index;}
int main(void){struct Handle a={{.index=3,.generation=1}},b={{.index=3,.generation=2}};int actual=same_slot(&a,&b);printf("c1118 handle=%d,%u\n",actual,(unsigned)b.generation);return !(actual&&b.generation==2);}
