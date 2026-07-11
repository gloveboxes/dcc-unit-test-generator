#include <stdio.h>
struct Map{int k;int v;};
static const struct Map m[3]={[1]={2,20},[0]={1,10},[2]={3,30}};
int main(void){printf("c9906 map=%d,%d\n",m[0].v,m[2].k);return 0;}
