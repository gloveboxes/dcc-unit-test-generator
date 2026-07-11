#include <stdio.h>
struct Message{int kind;union{char text[8];struct{int code;int detail;};};};
int main(void){struct Message text={.kind=1,.text={'O','K','\0'}},error={.kind=2,.code=404,.detail=7};printf("c1113 message=%s/%d,%d\n",text.text,error.code,error.detail);return 0;}
