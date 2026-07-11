#include <stdio.h>
#include <stdint.h>

/* The byte overlay assumes little-endian layout, shared by Z80 and the host. */
union Timestamp { uint32_t packed; struct { uint8_t ticks,seconds,minutes,hours; }; };
static uint32_t seconds_of_day(union Timestamp t){return (uint32_t)t.hours*3600U+(uint32_t)t.minutes*60U+t.seconds;}
int main(void){union Timestamp t={.ticks=25,.seconds=42,.minutes=17,.hours=9};uint32_t s=seconds_of_day(t);printf("c1112 timestamp=%lu,%u,%08lX\n",(unsigned long)s,(unsigned)t.ticks,(unsigned long)t.packed);return !(s==33462U&&t.ticks==25U&&t.packed==0x09112A19UL);}
