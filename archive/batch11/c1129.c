#include <stdio.h>
#include <stdbool.h>
struct Ring {
    int buf[8];
    int head, tail, count;
};
static bool ring_push(struct Ring *r, int v) {
    if (r->count == 8) return false;
    r->buf[r->tail] = v; r->tail = (r->tail + 1) % 8; r->count++; return true;
}
static bool ring_pop(struct Ring *r, int *v) {
    if (!r->count) return false;
    *v = r->buf[r->head]; r->head = (r->head + 1) % 8; r->count--; return true;
}
int main(void) {
    struct Ring r = {{0},0,0,0};
    for (int i = 1; i <= 5; i++) ring_push(&r, i * 10);
    int v = 0; ring_pop(&r, &v); ring_pop(&r, &v);
    printf("c1129 ring=%d,%d\n", v, r.count);
    return !(v == 20 && r.count == 3);
}
