#include <stdio.h>
struct Message{int type;union{char text[8];struct{int code;int detail;};};};
int main(void){struct Message m={.type=2,.code=404,.detail=7};printf("c1113 message=%d,%d\n",m.code,m.detail);return 0;}
