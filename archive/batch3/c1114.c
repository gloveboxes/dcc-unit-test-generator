#include <stdio.h>
struct Interval{struct{int start;int end;};};
static int contains(struct Interval i,int value){return value>=i.start&&value<=i.end;}
int main(void){struct Interval i={.start=10,.end=20};printf("c1114 interval=%d,%d\n",contains(i,10),contains(i,21));return 0;}
