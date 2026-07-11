#include <stdio.h>
#include <stdint.h>

struct Calibration { union { struct { int16_t offset,gain; }; int16_t coefficient[2]; }; };
static int calibrate(const struct Calibration *c,int raw){return c->offset+(long)raw*c->gain/100;}
int main(void){struct Calibration c={.offset=-12,.gain=125};int a=calibrate(&c,80),b=calibrate(&c,-20);printf("c1104 calibration=%d,%d,%d\n",a,b,(int)c.coefficient[1]);return !(a==88&&b==-37&&c.coefficient[1]==125);}
