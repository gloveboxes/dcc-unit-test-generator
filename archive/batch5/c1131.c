#include <stdio.h>
struct PairChoice{int tag;union{struct{int first;int second;};int single;};};
int main(void){struct PairChoice p={.tag=1,.first=4,.second=9};printf("c1131 choice=%d\n",p.first+p.second);return 0;}
