#include <stdio.h>
#include <stdint.h>
enum EndpointKind { LOCAL_PORT, REMOTE_NODE };
struct Endpoint { enum EndpointKind kind; union { uint16_t port; struct { uint8_t node,channel; }; }; };
static unsigned route(const struct Endpoint *endpoint){return endpoint->kind==LOCAL_PORT?endpoint->port:(unsigned)endpoint->node*16U+endpoint->channel;}
int main(void){struct Endpoint endpoint={.kind=REMOTE_NODE,.node=5,.channel=3};printf("c1127 endpoint=%u\n",route(&endpoint));return route(&endpoint)!=83U;}
