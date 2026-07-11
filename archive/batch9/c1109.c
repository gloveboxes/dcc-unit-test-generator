#include <stdio.h>
struct FreeBlock { union { struct FreeBlock *next; int allocated; }; };
static struct FreeBlock *take(struct FreeBlock **head){struct FreeBlock *block=*head;if(block)*head=block->next;return block;}
int main(void){struct FreeBlock blocks[3];blocks[0].next=&blocks[1];blocks[1].next=&blocks[2];blocks[2].next=0;struct FreeBlock *head=&blocks[0],*a=take(&head);a->allocated=1;printf("c1109 pool=%d,%d\n",a->allocated,head==&blocks[1]);return !(a->allocated==1&&head==&blocks[1]);}
