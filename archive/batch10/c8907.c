#include <stdio.h>

struct Deque { int data[5]; int head; int count; };

static int push_back(struct Deque *d, int value)
{
    if (d->count == 5) return 0;
    d->data[(d->head + d->count) % 5] = value; ++d->count; return 1;
}
static int push_front(struct Deque *d, int value)
{
    if (d->count == 5) return 0;
    d->head = (d->head + 4) % 5; d->data[d->head] = value; ++d->count; return 1;
}
static int pop_back(struct Deque *d)
{
    int value;
    value = d->data[(d->head + d->count - 1) % 5]; --d->count; return value;
}

int main(void)
{
    struct Deque d = {{0,0,0,0,0},0,0};
    int a, b;
    push_back(&d, 4); push_back(&d, 8); push_front(&d, 2); push_back(&d, 16);
    a = pop_back(&d); b = pop_back(&d);
    printf("c8907 deque=%d,%d,%d\n", a, b, d.count);
    return !(a == 16 && b == 8 && d.count == 2);
}
