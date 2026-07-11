#include <stdio.h>
#include <stdint.h>
union DeviceId { uint8_t bytes[6]; struct { uint8_t vendor[3]; uint8_t serial[3]; }; };
static unsigned checksum(const union DeviceId *id){unsigned sum=0;for(int i=0;i<6;++i)sum+=id->bytes[i];return sum;}
int main(void){union DeviceId id={.vendor={0,1,2},.serial={3,4,5}};printf("c1123 device=%u,%u\n",checksum(&id),(unsigned)id.serial[2]);return !(checksum(&id)==15U&&id.serial[2]==5U);}
