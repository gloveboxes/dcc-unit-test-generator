#include <stdio.h>
struct Permission{union{unsigned word;struct{unsigned read:1;unsigned write:1;unsigned execute:1;};};};
int main(void){struct Permission p={.read=1,.write=1,.execute=0};printf("c1120 permission=%u\n",p.word);return 0;}
