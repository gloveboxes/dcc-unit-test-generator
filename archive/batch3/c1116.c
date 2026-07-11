#include <stdio.h>
struct Pair{struct{int first;int second;};};
struct Choice{int tag;union{struct Pair pair;struct{int one;int two;};};};
int main(void){struct Choice c={.tag=1,.one=7,.two=11};printf("c1116 choice=%d,%d/%d\n",c.tag,c.one,c.two);return 0;}
