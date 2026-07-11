#include <stdio.h>
#include <stdint.h>

enum Band { OFFPEAK, STANDARD, PEAK, BAND_COUNT };
struct Tariff { uint16_t limit; uint16_t cents; };
static const struct Tariff tariffs[BAND_COUNT]={[PEAK]={.limit=50,.cents=18},[OFFPEAK]={.limit=100,.cents=7},[STANDARD]={.limit=75,.cents=11}};
static uint32_t cost(enum Band band,uint16_t units){const struct Tariff *t=&tariffs[band];uint16_t billed=units<t->limit?units:t->limit;return (uint32_t)billed*t->cents;}
int main(void){uint32_t a=cost(PEAK,42),b=cost(OFFPEAK,120);printf("c9901 tariff=%lu,%lu\n",(unsigned long)a,(unsigned long)b);return !(a==756U&&b==700U);}
