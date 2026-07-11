#include <stdio.h>

static void heap_push(int heap[], int *size, int value)
{
    int child;
    int parent;
    child = (*size)++;
    while (child > 0) {
        parent = (child - 1) / 2;
        if (heap[parent] <= value) break;
        heap[child] = heap[parent];
        child = parent;
    }
    heap[child] = value;
}

static int heap_pop(int heap[], int *size)
{
    int result;
    int value;
    int parent;
    int child;
    result = heap[0];
    value = heap[--(*size)];
    parent = 0;
    while ((child = parent * 2 + 1) < *size) {
        if (child + 1 < *size && heap[child + 1] < heap[child]) ++child;
        if (heap[child] >= value) break;
        heap[parent] = heap[child];
        parent = child;
    }
    if (*size > 0) heap[parent] = value;
    return result;
}

int main(void)
{
    int heap[6];
    int size = 0;
    int first;
    int second;
    heap_push(heap, &size, 9); heap_push(heap, &size, 3);
    heap_push(heap, &size, 7); heap_push(heap, &size, 1);
    first = heap_pop(heap, &size); second = heap_pop(heap, &size);
    printf("c8902 heap=%d,%d,%d\n", first, second, size);
    return !(first == 1 && second == 3 && size == 2);
}
