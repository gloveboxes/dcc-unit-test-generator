#include <stdio.h>
struct ResultInfo{int success;union{int code;const char* err;};};
static int get_code(struct ResultInfo r){return r.success?r.code:-1;}
int main(void){printf("c1109 res=%d\n",get_code((struct ResultInfo){1,{.code=200}}));return 0;}
