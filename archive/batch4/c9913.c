#include <stdio.h>
struct Status{int code;const char *label;};
static const struct Status table[]={{200,"ok"},{404,"missing"},{500,"error"}};
int main(void){int i;for(i=0;i<3;++i)if(table[i].code==404)printf("c9913 status=%s/%d\n",table[i].label,table[i].code);return 0;}
