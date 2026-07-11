#include <stdio.h>
enum ValueKind{VALUE_NUMBER,VALUE_TEXT};
struct Value{enum ValueKind kind;union{int number;struct{char text[8];};};};
int main(void){struct Value a={VALUE_NUMBER,{.number=27}};struct Value b={VALUE_TEXT,{.text={'o','k','\0'}}};printf("c1112 value=%d/%d,%s\n",a.kind,a.number,b.text);return 0;}
