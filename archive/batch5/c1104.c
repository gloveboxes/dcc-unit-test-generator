#include <stdio.h>
enum Kind{KIND_INT,KIND_CHAR};
struct Value{enum Kind kind;union{int number;char letter;};};
int main(void){struct Value v={KIND_INT,{.number=42}};printf("c1104 value=%d,%d\n",v.kind,v.number);return 0;}
