#include <stdio.h>
struct Segment{struct{int start;int end;};};
static int contains(struct Segment s,int v){return v>=s.start&&v<=s.end;}
int main(void){struct Segment s={.start=10,.end=20};printf("c1124 segment=%d,%d\n",contains(s,10),contains(s,21));return 0;}
