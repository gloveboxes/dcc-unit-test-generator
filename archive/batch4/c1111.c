#include <stdio.h>
enum ResultKind{RESULT_OK,RESULT_ERROR};
struct Result{enum ResultKind kind;union{int value;int error;};};
static int unwrap(struct Result result){return result.kind==RESULT_OK?result.value:-result.error;}
int main(void){struct Result good={RESULT_OK,{.value=18}},bad={RESULT_ERROR,{.error=5}};printf("c1111 result=%d\n",unwrap(good)+unwrap(bad));return 0;}
