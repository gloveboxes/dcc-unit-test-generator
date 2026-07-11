#include <stdio.h>
enum EventKind{EVENT_OPEN,EVENT_CLOSE};
struct Event{enum EventKind kind;union{int handle;char reason;};};
int main(void){struct Event e={EVENT_OPEN,{.handle=12}};printf("c1105 event=%d,%d\n",e.kind,e.handle);return 0;}
