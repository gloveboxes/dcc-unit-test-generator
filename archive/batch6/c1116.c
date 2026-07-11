#include <stdio.h>
struct Message{int type;union{struct{int source;int target;};struct{int code;int flags;};};};
int main(void){struct Message m={1,{.source=4,.target=9}};printf("c1116 message=%d,%d,%d\n",m.type,m.source,m.target);return 0;}
