#include <stdio.h>
struct Time{int hour;int minute;int second;};
static int seconds(struct Time t){return t.hour*3600+t.minute*60+t.second;}
int main(void){struct Time start={9,45,30},end={11,2,10};printf("c9916 time=%d\n",seconds(end)-seconds(start));return 0;}
