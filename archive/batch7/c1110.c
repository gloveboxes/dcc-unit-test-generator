#include <stdio.h>
struct ValueBox{enum{V_INT,V_STR} k;union{int v;char s[4];};};
int main(void){struct ValueBox b={V_INT,{.v=99}};printf("c1110 box=%d,%d\n",b.k,b.v);return 0;}
