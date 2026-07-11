#include <stdio.h>
struct Node{int value;struct Node *next;};
static void insert_after(struct Node *node,struct Node *added){added->next=node->next;node->next=added;}
static int sum(const struct Node *node){int total=0;while(node){total+=node->value;node=node->next;}return total;}
int main(void){struct Node a={2,0},b={5,0},c={7,0};insert_after(&a,&c);insert_after(&a,&b);printf("c8934 list=%d,%d\n",sum(&a),a.next->value);return !(sum(&a)==14&&a.next->value==5);}
