#include <stdio.h>
#include <stdint.h>

struct Snapshot { int generation;union { struct { uint16_t ready,failed,pending; };uint16_t counts[3]; }; };
static int health(const struct Snapshot *s){int total=s->ready+s->failed+s->pending;return total?((int)s->ready*100/total)-(int)s->failed*10:0;}
int main(void){struct Snapshot s={.generation=8,.ready=18,.failed=1,.pending=5};int h=health(&s);printf("c1124 snapshot=%d,%u,%d\n",h,(unsigned)s.counts[2],s.generation);return !(h==65&&s.counts[2]==5U&&s.generation==8);}
