#include <stdio.h>
struct Event{int id;union{struct{int x;int y;};int code;};};
int main(void){struct Event events[2]={{1,{.x=4,.y=6}},{2,{.code=404}}};printf("c1107 event=%d,%d/%d\n",events[0].x,events[0].y,events[1].code);return 0;}
