#include <stdio.h>

enum EventType { EVENT_KEY, EVENT_MOVE };
struct Event { enum EventType type; union { struct { char key; }; struct { int x; int y; }; }; };
int main(void)
{
    struct Event events[2] = {{EVENT_KEY, {.key = 'K'}}, {EVENT_MOVE, {.x = 4, .y = 9}}};
    printf("c1106 events=%c/%d,%d\n", events[0].key, events[1].x, events[1].y);
    return 0;
}
