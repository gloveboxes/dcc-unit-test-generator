#include <stdio.h>
struct Record{int id;char tag;int score;};
int main(void){struct Record r={.score=87,.tag='Q',.id=12};printf("c9911 designstruct=%d/%c/%d\n",r.id,r.tag,r.score);return 0;}
