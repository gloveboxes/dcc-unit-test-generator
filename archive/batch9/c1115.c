#include <stdio.h>
#include <stdint.h>
/* Nibble overlay uses implementation-defined bit-field order verified on dcc and Clang. */
union Bcd { uint8_t byte; struct { unsigned low:4; unsigned high:4; }; };
static unsigned decimal(const union Bcd *bcd){return bcd->high*10U+bcd->low;}
int main(void){union Bcd value={.byte=0x42U};printf("c1115 bcd=%u\n",decimal(&value));return decimal(&value)!=42U;}
