#include <stdio.h>
struct Pair{union{struct{int first;int second;};int values[2];};};
int main(void){struct Pair p={{.first=6,.second=7}};printf("c1120 pair=%d,%d\n",p.values[0],p.values[1]);return 0;}
