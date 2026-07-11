#include <stdio.h>
struct Month{const char *name;int days;};
static const struct Month months[4]={[0]={"Jan",31},[1]={"Feb",28},[2]={"Mar",31},[3]={"Apr",30}};
int main(void){printf("c9901 months=%s/%d,%s/%d\n",months[1].name,months[1].days,months[3].name,months[3].days);return 0;}
