#include <stdio.h>
#define CAP 16
static int queue_enq(int data[],int *head,int *tail,int value){int next=(*tail+1)%CAP;if(next==*head)return 0;data[*tail]=value;*tail=next;return 1;}
static int queue_deq(const int data[],int *head,int tail,int *value){if(*head==tail)return 0;*value=data[*head];*head=(*head+1)%CAP;return 1;}
int main(void){int data[CAP],head=0,tail=0,v=0;queue_enq(data,&head,&tail,10);queue_enq(data,&head,&tail,20);queue_deq(data,&head,tail,&v);printf("c8919 queue=%d,%d\n",v,tail-head);return !(v==10&&tail-head==1);}
