#include <stdio.h>
struct IPv4{union{unsigned long value;struct{unsigned char first;unsigned char second;unsigned char third;unsigned char fourth;};};};
int main(void){struct IPv4 ip;ip.first=192;ip.second=168;ip.third=1;ip.fourth=10;printf("c1105 ipv4=%u.%u.%u.%u\n",ip.first,ip.second,ip.third,ip.fourth);return 0;}
