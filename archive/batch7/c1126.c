#include <stdio.h>
struct DeviceInfo{unsigned ver:3;unsigned rev:5;};
static int calc_ver(struct DeviceInfo d){return d.ver*10+d.rev;}
int main(void){printf("c1126 dev=%d\n",calc_ver((struct DeviceInfo){2,5}));return 0;}
