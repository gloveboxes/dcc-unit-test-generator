#include <stdio.h>
struct StateMachine{int state;union{int counter;struct{unsigned char cur;unsigned char next;};};};
int main(void){struct StateMachine sm={1,{.cur=0,.next=1}};printf("c1116 sm=%d,%d\n",sm.state,sm.next);return 0;}
