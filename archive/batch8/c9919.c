#include <stdio.h>
struct DateBits { unsigned day:5, month:4, year:7; };
static int valid(struct DateBits d) { return d.day>=1 && d.day<=31 && d.month>=1 && d.month<=12; }
int main(void) { struct DateBits d={.year=26,.month=7,.day=10}; int ok=valid(d); printf("c9919 date=%d,%u\n",ok,d.year); return !(ok && d.year==26); }
