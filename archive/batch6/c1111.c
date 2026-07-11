#include <stdio.h>
struct Node{int value;union{struct{struct Node *next;};struct Node *link;};};
int main(void){struct Node a={1,{.next=0}},b={2,{.next=0}};a.next=&b;printf("c1111 nodes=%d,%d\n",a.value,a.next->value);return 0;}
