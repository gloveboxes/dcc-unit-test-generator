#include <stdio.h>
struct AnyEvent{enum{E_KEY,E_MOUSE} type;union{int keyval;struct{int x;int y;};};};
int main(void){struct AnyEvent e={E_MOUSE,{.x=100,.y=200}};printf("c1120 ev=%d,%d,%d\n",e.type,e.x,e.y);return 0;}
