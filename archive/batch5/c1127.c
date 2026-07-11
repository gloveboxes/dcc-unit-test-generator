#include <stdio.h>
struct Result{int ok;union{int value;int error;};};
static int unwrap(struct Result r){return r.ok?r.value:-r.error;}
int main(void){struct Result a={1,{.value=9}},b={0,{.error=2}};printf("c1127 result=%d\n",unwrap(a)+unwrap(b));return 0;}
