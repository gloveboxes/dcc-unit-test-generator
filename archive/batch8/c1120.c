#include <stdio.h>
struct Error { int domain; union { struct { int code,severity; }; int packed[2]; }; };
int main(void){struct Error e={2,{.code=14,.severity=3}};int score=e.domain*100+e.code*10+e.severity;printf("c1120 error=%d,%d\n",score,e.packed[1]);return !(score==343&&e.severity==3);}
