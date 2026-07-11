#include <stdio.h>
enum ValueKind { VALUE_INT, VALUE_BOOL };
struct Value { enum ValueKind kind; union { int integer; int boolean; }; };
static struct Value add(struct Value a,struct Value b){struct Value out={.kind=VALUE_INT,.integer=a.integer+b.integer};return out;}
int main(void){struct Value stack[3]={{.kind=VALUE_INT,.integer=17},{.kind=VALUE_INT,.integer=25}};stack[0]=add(stack[0],stack[1]);printf("c1126 vm=%d,%d\n",stack[0].integer,(int)stack[0].kind);return !(stack[0].integer==42&&stack[0].kind==VALUE_INT);}
