#include <stdio.h>
#include <stdint.h>

struct Route { uint8_t prefix; union { struct { uint8_t gateway,cost; }; struct { uint8_t nextHop,metric; }; }; };
static const struct Route *best(const struct Route *r,int n,uint8_t prefix){const struct Route *out=0;for(int i=0;i<n;++i)if(r[i].prefix==prefix&&(!out||r[i].metric<out->metric))out=&r[i];return out;}
int main(void){struct Route table[4]={{.prefix=10,.gateway=2,.cost=8},{.prefix=10,.gateway=5,.cost=3},{.prefix=20,.gateway=4,.cost=1},{.prefix=10,.gateway=7,.cost=6}};const struct Route *r=best(table,4,10);printf("c1109 routing=%u,%u\n",(unsigned)r->nextHop,(unsigned)r->metric);return !(r->nextHop==5U&&r->metric==3U);}
