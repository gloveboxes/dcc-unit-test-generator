#include <stdio.h>
#include <stdint.h>
/* Byte overlay assumes the little-endian Z80 and test host. */
union Status { uint16_t word; struct { uint8_t faults,mode; }; };
static int fault_count(uint8_t value){int count=0;for(;value;value>>=1)count+=value&1U;return count;}
int main(void){union Status status={.faults=0x2DU,.mode=3U};printf("c1118 status=%d,%u\n",fault_count(status.faults),(unsigned)status.mode);return !(fault_count(status.faults)==4&&status.word==0x032DU);}
