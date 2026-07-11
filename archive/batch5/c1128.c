#include <stdio.h>
struct Coordinates{struct{int latitude;int longitude;};};
int main(void){struct Coordinates c={.latitude=51,.longitude=-1};printf("c1128 coords=%d,%d\n",c.latitude,c.longitude);return 0;}
