#include <stdio.h>
struct Permissions{union{unsigned word;struct{unsigned read:1;unsigned write:1;unsigned execute:1;};};};
int main(void){struct Permissions p={.read=1,.write=1,.execute=0};printf("c1103 perms=%u,%u\n",p.word,p.write);return 0;}
