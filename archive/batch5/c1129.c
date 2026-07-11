#include <stdio.h>
struct Op{int code;union{struct{int a;int b;};int immediate;};};
int main(void){struct Op op={.code=2,.a=6,.b=7};printf("c1129 op=%d\n",op.a*op.b);return 0;}
