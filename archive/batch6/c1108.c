#include <stdio.h>
struct Value{int tag;union{int integer;char text[4];};};
static int get_integer(struct Value v){return v.tag==0?v.integer:-1;}
int main(void){struct Value v={0,{.integer=42}};printf("c1108 value=%d\n",get_integer(v));return 0;}
