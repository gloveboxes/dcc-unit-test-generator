#include <stdio.h>
enum ResultKind{RESULT_OK,RESULT_FAIL};
struct Result{enum ResultKind kind;union{int value;int error;};};
static int unwrap(struct Result r){return r.kind==RESULT_OK?r.value:-r.error;}
int main(void){struct Result a={RESULT_OK,{21}},b={RESULT_FAIL,{4}};printf("c1107 result=%d\n",unwrap(a)+unwrap(b));return 0;}
