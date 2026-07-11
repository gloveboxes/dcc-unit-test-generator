#include <stdio.h>
struct Entry{struct{int key;int value;};struct Entry *next;};
int main(void){struct Entry tail={.key=9,.value=90,.next=0};struct Entry head={.key=4,.value=40,.next=&tail};printf("c1107 chain=%d,%d/%d,%d\n",head.key,head.value,head.next->key,head.next->value);return 0;}
