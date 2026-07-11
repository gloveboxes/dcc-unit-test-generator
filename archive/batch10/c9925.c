#include <stdio.h>
#include <stdint.h>

struct Sample { unsigned magnitude:10;unsigned channel:3;unsigned alarm:1;unsigned quality:2; };
static int score(struct Sample s){return (int)s.magnitude+(int)s.channel*100+(int)s.quality*25+(s.alarm?500:0);}
int main(void){struct Sample a={.magnitude=620,.channel=3,.quality=2},b={.magnitude=17,.channel=1,.alarm=1,.quality=1};int total=score(a)+score(b);printf("c9925 sensorword=%d,%u\n",total,(unsigned)b.alarm);return !(total==1612&&b.alarm==1U);}
