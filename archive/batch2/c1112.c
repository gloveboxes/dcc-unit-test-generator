#include <stdio.h>
struct Message{int type;union{struct{char text[8];};int code;};};
int main(void){struct Message m[2]={{1,{.text={'O','K','\0'}}},{2,{.code=500}}};printf("c1112 message=%s/%d\n",m[0].text,m[1].code);return 0;}
