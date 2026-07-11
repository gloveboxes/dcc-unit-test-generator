#include <stdio.h>
#include <stdint.h>

enum MetricKind { COUNTER,GAUGE,DISTRIBUTION };struct Metric { int id;enum MetricKind kind;union { uint32_t counter;int gauge;struct { int minimum,maximum,count; }; }; };
static long summarize(const struct Metric *m){if(m->kind==COUNTER)return (long)m->counter;if(m->kind==GAUGE)return m->gauge;return (long)(m->maximum-m->minimum)*m->count;}
int main(void){struct Metric m[3]={{.id=1,.kind=COUNTER,.counter=40000U},{.id=2,.kind=GAUGE,.gauge=-15},{.id=3,.kind=DISTRIBUTION,.minimum=3,.maximum=11,.count=5}};long total=0;for(int i=0;i<3;++i)total+=summarize(&m[i]);printf("c1129 metrics=%ld,%d\n",total,m[2].count);return !(total==40025L&&m[2].count==5);}
