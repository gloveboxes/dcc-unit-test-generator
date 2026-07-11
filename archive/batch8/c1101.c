#include <stdio.h>
enum EventKind { EVENT_KEY, EVENT_POINT };
struct Event { enum EventKind kind; union { int key; struct { int x, y; }; }; };
static int event_value(const struct Event *e) { return e->kind==EVENT_KEY ? e->key : e->x+e->y; }
int main(void) { struct Event e={EVENT_POINT,{.x=12,.y=8}}; int actual=event_value(&e); printf("c1101 event=%d\n",actual); return actual!=20; }
