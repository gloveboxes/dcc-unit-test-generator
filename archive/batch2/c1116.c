#include <stdio.h>
struct Pair{int first;int second;};
struct Choice{int selected;union{struct Pair pair;int scalar;};};
int main(void){struct Choice c={1,{.pair={4,9}}};printf("c1116 choice=%d,%d\n",c.pair.first,c.pair.second);return 0;}
