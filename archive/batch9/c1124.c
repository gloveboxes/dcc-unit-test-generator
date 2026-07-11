#include <stdio.h>
#include <stdbool.h>
enum FieldKind { FIELD_INT, FIELD_TEXT };
struct Field { enum FieldKind kind; union { int number; const char *text; }; };
static bool equal(const struct Field *a,const struct Field *b){if(a->kind!=b->kind)return false;if(a->kind==FIELD_INT)return a->number==b->number;const char *x=a->text,*y=b->text;while(*x&&*x==*y){++x;++y;}return *x==*y;}
int main(void){struct Field a={.kind=FIELD_TEXT,.text="CPM"},b={.kind=FIELD_TEXT,.text="CPM"},c={.kind=FIELD_INT,.number=3};printf("c1124 fields=%d,%d\n",(int)equal(&a,&b),(int)equal(&a,&c));return !(equal(&a,&b)&&!equal(&a,&c));}
