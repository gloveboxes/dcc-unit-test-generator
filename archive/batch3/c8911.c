#include <stdio.h>
struct Queue{int data[5];int head;int tail;int count;};
static void put(struct Queue *q,int v){q->data[q->tail]=v;q->tail=(q->tail+1)%5;++q->count;}
static int get(struct Queue *q){int v;q->head=q->head%5;v=q->data[q->head];q->head=(q->head+1)%5;--q->count;return v;}
int main(void){struct Queue q;int i,total;q.head=0;q.tail=0;q.count=0;for(i=1;i<=4;++i)put(&q,i*3);total=get(&q)+get(&q);put(&q,20);printf("c8911 queue=%d,%d\n",total,q.count);return 0;}
