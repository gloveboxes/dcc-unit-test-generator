#include <stdio.h>
#define CAP 8
struct Stack{int data[CAP];int top;};
static void push(struct Stack *s,int v){if(s->top<CAP)s->data[s->top++]=v;}
static int pop(struct Stack *s,int *v){if(!s->top)return 0;*v=s->data[--s->top];return 1;}
static void enq(struct Stack *in,struct Stack *out,int v){push(in,v);}
static int deq(struct Stack *in,struct Stack *out,int *v){if(!out->top){int t;while(pop(in,&t))push(out,t);}return pop(out,v);}
int main(void){struct Stack in={{0},0},out={{0},0};int v=0;enq(&in,&out,7);enq(&in,&out,14);deq(&in,&out,&v);printf("c8926 q2s=%d,%d\n",v,out.top);return !(v==7&&out.top==1);}
