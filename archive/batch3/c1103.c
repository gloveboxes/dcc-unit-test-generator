#include <stdio.h>
enum Event{EVT_START,EVT_DATA,EVT_STOP};
struct Message{enum Event type;union{int sequence;char text[6];};};
int main(void){struct Message a={EVT_DATA,{.sequence=17}};struct Message b={EVT_STOP,{.text={'d','o','n','e','\0'}}};printf("c1103 event=%d/%d,%s\n",a.type,a.sequence,b.text);return 0;}
