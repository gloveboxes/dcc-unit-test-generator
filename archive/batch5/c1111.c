#include <stdio.h>
struct Pair{int first;int second;};
struct Choice{int tag;union{struct Pair pair;struct{int one;int two;};};};
int main(void){struct Choice c={.tag=1,.one=6,.two=8};printf("c1111 choice=%d,%d\n",c.tag,c.one+c.two);return 0;}
