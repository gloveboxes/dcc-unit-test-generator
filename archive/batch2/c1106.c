#include <stdio.h>
enum EventKind{EVENT_OPEN,EVENT_CLOSE};
struct Event{enum EventKind kind;union{int handle;char reason;};};
int main(void){struct Event events[2]={{EVENT_OPEN,{.handle=12}},{EVENT_CLOSE,{.reason='X'}}};printf("c1106 events=%d/%c\n",events[0].handle,events[1].reason);return 0;}
