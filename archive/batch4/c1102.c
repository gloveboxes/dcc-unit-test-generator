#include <stdio.h>
enum ValueType{VALUE_INT,VALUE_CHAR};
struct Value{enum ValueType type;union{int number;char character;};};
static int as_int(struct Value v){return v.type==VALUE_INT?v.number:(int)v.character;}
int main(void){struct Value a={VALUE_INT,{.number=37}},b={VALUE_CHAR,{.character='A'}};printf("c1102 value=%d,%d\n",as_int(a),as_int(b));return 0;}
