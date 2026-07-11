#include <stdio.h>
struct Measure{enum{MEASURE_INT,MEASURE_PAIR} kind;union{int scalar;struct{int low;int high;};};};
static int midpoint(struct Measure m){return m.kind==MEASURE_INT?m.scalar:(m.low+m.high)/2;}
int main(void){struct Measure m={MEASURE_PAIR,{.low=10,.high=18}};printf("c1132 measure=%d\n",midpoint(m));return 0;}
