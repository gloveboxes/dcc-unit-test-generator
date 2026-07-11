#include <stdio.h>
#include <stdbool.h>
struct Cache {
    int keys[8];
    int vals[8];
    int order[8];
    int size;
    int cap;
    int tick;
};
static int cache_get(struct Cache *c, int key) {
    for (int i = 0; i < c->size; i++)
        if (c->keys[i] == key) { c->order[i] = c->tick++; return c->vals[i]; }
    return -1;
}
static void cache_put(struct Cache *c, int key, int val) {
    for (int i = 0; i < c->size; i++)
        if (c->keys[i] == key) { c->vals[i] = val; c->order[i] = c->tick++; return; }
    if (c->size < c->cap) {
        c->keys[c->size] = key; c->vals[c->size] = val; c->order[c->size] = c->tick++; c->size++;
    } else {
        int lru = 0;
        for (int i = 1; i < c->size; i++) if (c->order[i] < c->order[lru]) lru = i;
        c->keys[lru] = key; c->vals[lru] = val; c->order[lru] = c->tick++;
    }
}
int main(void) {
    struct Cache c = {{0},{0},{0},0,4,0};
    cache_put(&c,1,10); cache_put(&c,2,20); cache_put(&c,3,30); cache_put(&c,4,40);
    cache_get(&c,1); cache_get(&c,3);
    cache_put(&c,5,50);
    int v2 = cache_get(&c,2), v5 = cache_get(&c,5);
    printf("c1120 cache=%d,%d\n", v2, v5);
    return !(v2 == -1 && v5 == 50);
}
