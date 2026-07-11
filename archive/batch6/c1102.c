#include <stdio.h>
struct Packet{union{struct{unsigned char lo;unsigned char hi;};unsigned short word;};};
int main(void){struct Packet p;p.word=0x1234;printf("c1102 packet=%u\n",p.word);return 0;}
