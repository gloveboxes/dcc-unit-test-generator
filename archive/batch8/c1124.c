#include <stdio.h>
enum ResponseKind { RESPONSE_OK,RESPONSE_ERROR };
struct Response { enum ResponseKind kind; union { struct { int status,bytes; }; struct { int error,retry; }; }; };
static int successful(const struct Response *r){return r->kind==RESPONSE_OK&&r->status==200;}
int main(void){struct Response r={RESPONSE_OK,{.status=200,.bytes=64}};int actual=successful(&r);printf("c1124 response=%d,%d\n",actual,r.bytes);return !(actual&&r.bytes==64);}
