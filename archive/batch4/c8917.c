#include <stdio.h>
struct Counter{int value;int limit;};
static int advance(struct Counter *counter){if(counter->value<counter->limit)++counter->value;return counter->value;}
int main(void){struct Counter counter={2,4};int first,second,third;first=advance(&counter);second=advance(&counter);third=advance(&counter);printf("c8917 counter=%d,%d,%d\n",first,second,third);return 0;}
