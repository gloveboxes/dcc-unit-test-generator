#include <stdio.h>
struct Pair{int first;int second;};
struct Choice{int tag;union{struct Pair pair;struct{int one;int two;};};};
int main(void){struct Choice choice={.tag=1,.one=6,.two=9};printf("c1114 choice=%d,%d/%d\n",choice.tag,choice.one,choice.two);return 0;}
