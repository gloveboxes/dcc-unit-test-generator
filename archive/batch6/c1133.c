#include <stdio.h>
struct Permission{unsigned read:1;unsigned write:1;unsigned execute:1;};
static int can_modify(struct Permission p){return p.write&&p.read;}
int main(void){struct Permission p={1,1,0};printf("c1133 permission=%d\n",can_modify(p));return 0;}
