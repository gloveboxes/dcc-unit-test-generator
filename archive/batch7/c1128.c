#include <stdio.h>
struct Memory{enum{M_RAM,M_ROM} t;union{unsigned sz;struct{unsigned lb;unsigned ub;};};};
int main(void){struct Memory m={M_RAM,{.sz=1024}};printf("c1128 mem=%d,%u\n",m.t,m.sz);return 0;}
