#include <stdio.h>

enum AckKind { ACK,NAK,DEFER };struct Ack { int sequence;enum AckKind kind;union { int window;struct { int error,offset; };struct { int queue,delay; }; }; };
static int next(const struct Ack *a){if(a->kind==ACK)return a->sequence+a->window;if(a->kind==NAK)return a->sequence-a->offset;return a->sequence+a->delay;}
int main(void){struct Ack a={.sequence=20,.kind=ACK,.window=4},b={.sequence=20,.kind=NAK,.error=3,.offset=5},c={.sequence=20,.kind=DEFER,.queue=2,.delay=7};printf("c1125 acknowledgments=%d,%d,%d\n",next(&a),next(&b),next(&c));return !(next(&a)==24&&next(&b)==15&&next(&c)==27);}
