#include <stdio.h>
struct Time{int hour;int minute;};
static struct Time add_minutes(struct Time t,int amount){t.minute+=amount;while(t.minute>=60){t.minute-=60;++t.hour;}return t;}
int main(void){struct Time t=add_minutes((struct Time){9,45},80);printf("c9910 time=%d:%d\n",t.hour,t.minute);return 0;}
