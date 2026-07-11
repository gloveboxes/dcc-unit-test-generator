#include <stdio.h>
#include <stdint.h>
struct CheckFrame { union { struct { uint8_t type,length; }; uint8_t header[2]; }; uint8_t data[4]; };
static uint8_t checksum(const struct CheckFrame *frame){unsigned sum=frame->type+frame->length;for(int i=0;i<frame->length;++i)sum+=frame->data[i];return (uint8_t)(0U-sum);}
int main(void){struct CheckFrame frame={.type=2,.length=4,.data={10,20,30,40}};uint8_t check=checksum(&frame);printf("c1130 checksum=%u,%u\n",(unsigned)check,(unsigned)frame.header[1]);return !(check==150U&&frame.header[1]==4U);}
