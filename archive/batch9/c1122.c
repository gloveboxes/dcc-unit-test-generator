#include <stdio.h>
#include <stdint.h>
union PackedDate { uint16_t bits; struct { unsigned day:5; unsigned month:4; unsigned year:7; }; };
int main(void){union PackedDate date={.bits=0};date.year=44U;date.month=12U;date.day=31U;printf("c1122 date=%u-%u-%u\n",1980U+date.year,date.month,date.day);return !(date.year==44U&&date.month==12U&&date.day==31U);}
