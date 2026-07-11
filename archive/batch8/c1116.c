#include <stdio.h>
enum SensorKind { SENSOR_TEMP,SENSOR_LEVEL };
struct Sensor { enum SensorKind kind; union { int tenths_celsius; int percent; }; };
static int alarm(const struct Sensor *s){return s->kind==SENSOR_TEMP?s->tenths_celsius>300:s->percent<10;}
int main(void){struct Sensor s={SENSOR_TEMP,{.tenths_celsius=315}};int actual=alarm(&s);printf("c1116 sensor=%d\n",actual);return !actual;}
