#include <stdio.h>

struct Envelope { union { struct { int attack,decay,sustain,release; }; int stage[4]; }; };
static int amplitude(const struct Envelope *e,int tick){if(tick<e->attack)return tick*100/e->attack;tick-=e->attack;if(tick<e->decay)return 100-(100-e->sustain)*tick/e->decay;return e->sustain;}
int main(void){struct Envelope e={.attack=4,.decay=6,.sustain=55,.release=8};int a=amplitude(&e,2),b=amplitude(&e,7),c=amplitude(&e,20);printf("c1107 envelope=%d,%d,%d\n",a,b,c);return !(a==50&&b==78&&c==55);}
