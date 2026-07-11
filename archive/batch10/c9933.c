#include <stdio.h>
#include <stdint.h>

enum Unit { CELSIUS,FAHRENHEIT,KELVIN,UNITS };struct Conversion { int16_t scale,offset,divisor; };
static const struct Conversion to_tenths[UNITS]={[FAHRENHEIT]={.scale=5,.offset=-320,.divisor=9},[CELSIUS]={.scale=1,.offset=0,.divisor=1},[KELVIN]={.scale=1,.offset=-2732,.divisor=1}};
static int convert(enum Unit unit,int value){const struct Conversion *c=&to_tenths[unit];return (value+c->offset)*c->scale/c->divisor;}
int main(void){int a=convert(FAHRENHEIT,770),b=convert(KELVIN,3000),c=convert(CELSIUS,-125);printf("c9933 units=%d,%d,%d\n",a,b,c);return !(a==250&&b==268&&c==-125);}
