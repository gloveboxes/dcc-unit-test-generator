#include <stdio.h>

#define POOL_SIZE 4
struct Slot { int value; int next; };
struct Pool { struct Slot slots[POOL_SIZE]; int free_head; };

static void pool_init(struct Pool *pool)
{
    int i;
    for (i = 0; i < POOL_SIZE - 1; ++i) pool->slots[i].next = i + 1;
    pool->slots[POOL_SIZE - 1].next = -1; pool->free_head = 0;
}

static int pool_take(struct Pool *pool, int value)
{
    int index = pool->free_head;
    if (index < 0) return -1;
    pool->free_head = pool->slots[index].next; pool->slots[index].value = value;
    return index;
}

int main(void)
{
    struct Pool pool; int first; int second;
    pool_init(&pool); first = pool_take(&pool, 40); second = pool_take(&pool, 80);
    printf("c8918 pool=%d,%d,%d\n", first, second, pool.free_head);
    return !(first == 0 && second == 1 && pool.free_head == 2);
}
