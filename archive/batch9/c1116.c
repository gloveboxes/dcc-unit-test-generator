#include <stdio.h>
#include <stdint.h>
enum PayloadKind { PAYLOAD_CODE, PAYLOAD_PAIR };
struct Frame { uint8_t sequence; enum PayloadKind kind; union { uint16_t code; struct { uint8_t first,second; }; }; };
static unsigned payload_sum(const struct Frame *frame){return frame->kind==PAYLOAD_CODE?frame->code:(unsigned)frame->first+frame->second;}
int main(void){struct Frame frame={.sequence=9,.kind=PAYLOAD_PAIR,.first=20,.second=22};printf("c1116 frame=%u,%u\n",(unsigned)frame.sequence,payload_sum(&frame));return !(frame.sequence==9&&payload_sum(&frame)==42U);}
