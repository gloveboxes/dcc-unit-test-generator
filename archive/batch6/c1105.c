#include <stdio.h>
enum Kind{EV_START,EV_DATA,EV_STOP};
struct Event{enum Kind kind;union{int code;struct{int value;int count;};};};
int main(void){struct Event e={EV_DATA,{.value=7,.count=3}};printf("c1105 event=%d,%d,%d\n",e.kind,e.value,e.count);return 0;}
