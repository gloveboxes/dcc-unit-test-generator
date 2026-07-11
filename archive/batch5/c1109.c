#include <stdio.h>
enum ResultKind{RESULT_OK,RESULT_FAIL};
struct Result{enum ResultKind kind;union{int value;int error;};};
int main(void){struct Result a={RESULT_OK,{.value=21}},b={RESULT_FAIL,{.error=4}};printf("c1109 result=%d\n",a.value-b.error);return 0;}
