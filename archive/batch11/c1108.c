#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
enum EventKind { EV_KEY, EV_MOUSE, EV_TIMER };
struct Event {
    enum EventKind kind;
    uint32_t timestamp;
    union {
        struct { int keycode; bool pressed; };
        struct { int mx; int my; int button; };
        struct { int timer_id; };
    };
};
static int event_score(const struct Event *e) {
    if (e->kind == EV_KEY)   return e->keycode + (e->pressed ? 1000 : 0);
    if (e->kind == EV_MOUSE) return e->mx + e->my + e->button * 100;
    return e->timer_id;
}
int main(void) {
    struct Event ev = {.kind=EV_KEY, .timestamp=42U, .keycode=65, .pressed=true};
    int s = event_score(&ev);
    printf("c1108 event=%d,%u\n", s, (unsigned)ev.timestamp);
    return !(s == 1065 && ev.timestamp == 42U);
}
