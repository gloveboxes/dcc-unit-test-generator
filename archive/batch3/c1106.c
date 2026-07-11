#include <stdio.h>
enum MeasureKind{MEASURE_INT,MEASURE_FLOAT};
struct Measure{enum MeasureKind kind;union{int count;float ratio;};};
int main(void){struct Measure m={MEASURE_INT,{.count=42}};printf("c1106 measure=%d/%d\n",m.kind,m.count);return 0;}
