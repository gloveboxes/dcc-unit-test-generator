#include <stdio.h>
enum ResultCode{RESULT_OK,RESULT_EMPTY,RESULT_BAD};
struct Result{enum ResultCode code;union{int value;const char *message;};};
int main(void){struct Result r={RESULT_OK,{.value=99}};printf("c1114 result=%d,%d\n",r.code,r.value);return 0;}
