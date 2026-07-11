#include <stdio.h>
#include <stdint.h>

/* The word overlay assumes little-endian layout, shared by Z80 and the host. */
union Motor { uint16_t word; struct { unsigned speed:8;unsigned direction:1;unsigned brake:1;unsigned fault:1;unsigned reserved:5; }; };
static int effective(union Motor m){if(m.fault||m.brake)return 0;return m.direction?-(int)m.speed:(int)m.speed;}
int main(void){union Motor a={.speed=120,.direction=1},b={.speed=90,.brake=1};printf("c1113 motor=%d,%d,%04x\n",effective(a),effective(b),(unsigned)a.word);return !(effective(a)==-120&&effective(b)==0&&a.word==0x0178U);}
