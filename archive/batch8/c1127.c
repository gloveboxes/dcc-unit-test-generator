#include <stdio.h>
enum VariantKind { VARIANT_COUNT,VARIANT_LIMITS };
struct Variant { enum VariantKind kind; union { int count; struct { int low,high; }; }; };
static int width(const struct Variant *v){return v->kind==VARIANT_COUNT?v->count:v->high-v->low;}
int main(void){struct Variant v={VARIANT_LIMITS,{.low=10,.high=28}};int actual=width(&v);printf("c1127 variant=%d\n",actual);return actual!=18;}
