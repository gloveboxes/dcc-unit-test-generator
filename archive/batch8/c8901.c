#include <stdio.h>

#define CAPACITY 5
struct Queue { int data[CAPACITY]; int head; int count; };

static int push(struct Queue *q, int value)
{
    int tail;
    if (q->count == CAPACITY) return 0;
    tail = (q->head + q->count) % CAPACITY;
    q->data[tail] = value;
    ++q->count;
    return 1;
}

static int pop(struct Queue *q, int *value)
{
    if (q->count == 0) return 0;
    *value = q->data[q->head];
    q->head = (q->head + 1) % CAPACITY;
    --q->count;
    return 1;
}

int main(void)
{
    struct Queue q = {{0, 0, 0, 0, 0}, 0, 0};
    int value;
    push(&q, 12); push(&q, 24); pop(&q, &value); push(&q, 36);
    printf("c8901 queue=%d,%d,%d\n", value, q.data[q.head], q.count);
    return !(value == 12 && q.data[q.head] == 24 && q.count == 2);
}
