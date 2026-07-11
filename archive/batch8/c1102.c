#include <stdio.h>
struct Result { int ok; union { int value; const char *message; }; };
static int unwrap(const struct Result *r,int fallback){return r->ok?r->value:fallback;}
int main(void){struct Result a={1,{.value=42}},b={0,{.message="bad"}};int x=unwrap(&a,-1),y=unwrap(&b,-1);printf("c1102 result=%d,%d\n",x,y);return !(x==42&&y==-1);}
