#include <stdio.h>
struct PackedDate { union { unsigned short raw; struct { unsigned day:5; unsigned month:4; unsigned year:7; }; }; };
int main(void){struct PackedDate d;d.raw=0;d.year=26;d.month=7;d.day=10;printf("c1122 date=%u,%u,%u\n",d.year,d.month,d.day);return !(d.year==26&&d.month==7&&d.day==10);}
