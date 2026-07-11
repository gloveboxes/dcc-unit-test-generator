#include <stdio.h>
enum Kind{KIND_INT,KIND_CHAR};
struct Value{enum Kind kind;union{int number;char letter;};};
int main(void){struct Value v;v.kind=KIND_INT;v.number=73;printf("c1102 variant=%d/%d\n",v.kind,v.number);return 0;}
