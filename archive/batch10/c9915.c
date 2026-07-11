#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

struct Header { uint8_t version,flags,length,check; };
static bool valid(const struct Header *h){uint8_t sum=(uint8_t)(h->version+h->flags+h->length);return h->version<=3U&&(h->flags&0xE0U)==0U&&sum==h->check;}
int main(void){struct Header a={.version=2,.flags=0x13,.length=24,.check=45},b={.version=2,.flags=0x80,.length=1,.check=131};printf("c9915 headercheck=%d,%d\n",(int)valid(&a),(int)valid(&b));return !(valid(&a)&&!valid(&b));}
