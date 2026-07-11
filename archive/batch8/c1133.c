#include <stdio.h>
enum MetricKind { METRIC_VALUE,METRIC_RANGE };
struct Metric { enum MetricKind kind; union { long value; struct { int low,high; }; }; };
static long midpoint(const struct Metric *m){return m->kind==METRIC_VALUE?m->value:(m->low+m->high)/2;}
int main(void){struct Metric m={METRIC_RANGE,{.low=20,.high=30}};long actual=midpoint(&m);printf("c1133 metric=%ld\n",actual);return actual!=25L;}
