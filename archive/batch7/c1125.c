#include <stdio.h>
struct Token{enum{T_NUM,T_SYM} t;union{int n;char c;};};
static int get_n(struct Token t){return t.t==T_NUM?t.n:0;}
int main(void){printf("c1125 tok=%d\n",get_n((struct Token){T_NUM,{.n=42}}));return 0;}
