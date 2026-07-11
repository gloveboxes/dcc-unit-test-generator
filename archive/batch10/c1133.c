#include <stdio.h>
#include <stdint.h>

enum ExchangeKind { QUERY,UPDATE,CONFIRM };struct Exchange { uint8_t sequence;enum ExchangeKind kind;union { struct { uint8_t object,field; };struct { uint8_t address,value; };struct { uint8_t accepted,revision; }; }; };
static unsigned digest(const struct Exchange *e){if(e->kind==QUERY)return e->sequence+e->object*3U+e->field;if(e->kind==UPDATE)return e->sequence+e->address+e->value*2U;return e->sequence+e->accepted*10U+e->revision;}
int main(void){struct Exchange e[3]={{.sequence=1,.kind=QUERY,.object=4,.field=2},{.sequence=2,.kind=UPDATE,.address=8,.value=5},{.sequence=3,.kind=CONFIRM,.accepted=1,.revision=6}};unsigned sum=0;for(int i=0;i<3;++i)sum+=digest(&e[i]);printf("c1133 exchanges=%u,%u\n",sum,(unsigned)e[2].revision);return !(sum==54U&&e[2].revision==6U);}
