#include <stdio.h>
#include <stdint.h>
enum MessageKind { ACK_MESSAGE, DATA_MESSAGE };
struct Message { uint8_t sequence; enum MessageKind kind; union { uint8_t acknowledged; struct { uint8_t length; uint8_t bytes[4]; }; }; };
static unsigned sum(const struct Message *message){if(message->kind==ACK_MESSAGE)return message->acknowledged;unsigned total=0;for(int i=0;i<message->length;++i)total+=message->bytes[i];return total;}
int main(void){struct Message message={.sequence=7,.kind=DATA_MESSAGE,.length=4,.bytes={4,8,15,16}};printf("c1133 message=%u,%u\n",(unsigned)message.sequence,sum(&message));return !(message.sequence==7U&&sum(&message)==43U);}
