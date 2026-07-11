#include <stdio.h>
struct Pair{int first;int second;};
static struct Pair ordered(struct Pair p){if(p.first>p.second){int t=p.first;p.first=p.second;p.second=t;}return p;}
int main(void){struct Pair p=ordered((struct Pair){9,2});printf("c9911 pair=%d,%d\n",p.first,p.second);return 0;}
