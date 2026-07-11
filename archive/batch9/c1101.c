#include <stdio.h>
enum EventKind { KEY_EVENT, POINTER_EVENT };
struct Event { enum EventKind kind; union { struct { int key; int pressed; }; struct { int x,y; }; }; };
static int describe(const struct Event *event){return event->kind==KEY_EVENT?event->key:event->x+event->y;}
int main(void){struct Event event={.kind=POINTER_EVENT,.x=12,.y=7};int value=describe(&event);printf("c1101 event=%d\n",value);return value!=19;}
