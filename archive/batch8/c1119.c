#include <stdio.h>
enum ValueKind { VALUE_INT,VALUE_PAIR };
struct Value { enum ValueKind kind; union { int integer; struct { int first,second; }; }; };
static int sum(const struct Value *v){return v->kind==VALUE_INT?v->integer:v->first+v->second;}
int main(void){struct Value v={VALUE_PAIR,{.first=11,.second=31}};int actual=sum(&v);printf("c1119 value=%d\n",actual);return actual!=42;}
