#include <stdio.h>
enum MessageKind { MSG_DATA,MSG_ACK };
struct Message { enum MessageKind kind; union { struct { int id,length; }; int acknowledged_id; }; };
static int identifier(const struct Message *m){return m->kind==MSG_ACK?m->acknowledged_id:m->id;}
int main(void){struct Message m={MSG_DATA,{.id=17,.length=4}};int actual=identifier(&m);printf("c1114 message=%d,%d\n",actual,m.length);return !(actual==17&&m.length==4);}
