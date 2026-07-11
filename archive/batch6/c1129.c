#include <stdio.h>
struct WordPair{union{struct{unsigned short first;unsigned short second;};unsigned short words[2];};};
static unsigned total(struct WordPair p){return p.first+p.second;}
int main(void){struct WordPair p={.first=10,.second=20};printf("c1129 words=%u,%u\n",p.words[0],total(p));return 0;}
