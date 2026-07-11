#include <stdio.h>
struct Money{union{long cents;struct{int dollars;int remainder;};};};
int main(void){struct Money m;m.cents=12345;printf("c1110 money=%ld\n",m.cents);return 0;}
