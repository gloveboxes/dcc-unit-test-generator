#include <stdio.h>
struct Interval { union { struct { int begin,end; }; struct { int minimum,maximum; }; }; };
static int intersect(const struct Interval *a,const struct Interval *b,struct Interval *out){out->begin=a->begin>b->begin?a->begin:b->begin;out->end=a->end<b->end?a->end:b->end;return out->end>out->begin;}
int main(void){struct Interval a={.minimum=3,.maximum=12},b={.begin=8,.end=15},out;int ok=intersect(&a,&b,&out);printf("c1128 interval=%d,%d,%d\n",ok,out.begin,out.end);return !(ok&&out.begin==8&&out.end==12);}
