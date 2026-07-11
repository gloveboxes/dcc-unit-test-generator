#include <stdio.h>

struct Event { int tick; int code; };

static void heap_push(struct Event *h, int *n, struct Event e)
{
    int i, p; struct Event t;
    i = (*n)++; h[i] = e;
    while (i > 0) { p = (i - 1) / 2; if (h[p].tick <= h[i].tick) break; t = h[p]; h[p] = h[i]; h[i] = t; i = p; }
}
static struct Event heap_pop(struct Event *h, int *n)
{
    struct Event out, t; int i, child;
    out = h[0]; h[0] = h[--(*n)]; i = 0;
    for (;;) { child = i * 2 + 1; if (child >= *n) break; if (child + 1 < *n && h[child + 1].tick < h[child].tick) ++child; if (h[i].tick <= h[child].tick) break; t = h[i]; h[i] = h[child]; h[child] = t; i = child; }
    return out;
}

int main(void)
{
    struct Event h[6], e, input[4] = {{14,1},{3,2},{9,3},{6,4}};
    int n, order, i;
    n = 0;
    for (i = 0; i < 4; ++i) heap_push(h, &n, input[i]);
    order = 0; while (n) { e = heap_pop(h,&n); order = order * 10 + e.code; }
    printf("c8908 events=%d\n", order);
    return order != 2431;
}
