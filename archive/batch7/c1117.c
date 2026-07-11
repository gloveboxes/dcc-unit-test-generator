#include <stdio.h>
struct Access{unsigned read:1;unsigned write:1;unsigned exec:1;unsigned :5;};
static int can_exe(struct Access a){return a.exec;}
int main(void){struct Access a={1,0,1};printf("c1117 acc=%d\n",can_exe(a));return 0;}
