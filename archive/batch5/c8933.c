#include <stdio.h>
struct Queue{int a[5];int head;int tail;int count;};
static void put(struct Queue *q,int v){q->a[q->tail]=v;q->tail=(q->tail+1)%5;++q->count;}
static int get(struct Queue *q){int v=q->a[q->head];q->head=(q->head+1)%5;--q->count;return v;}
int main(void){struct Queue q={ {0,0,0,0,0},0,0,0};int value;put(&q,4);put(&q,9);value=get(&q);printf("c8933 queue=%d,%d\n",value,q.count);return 0;}
