#include <stdio.h>
struct Sensor{enum{SENSOR_TEMP,SENSOR_LEVEL} kind;union{int celsius;int percent;};};
int main(void){struct Sensor s={SENSOR_TEMP,{.celsius=21}};printf("c1118 sensor=%d,%d\n",s.kind,s.celsius);return 0;}
