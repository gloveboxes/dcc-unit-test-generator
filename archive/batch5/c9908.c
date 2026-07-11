#include <stdio.h>
struct Status{int code;const char *name;};
static const struct Status table[3]={[0]={200,"ok"},[1]={404,"missing"},[2]={500,"error"}};
int main(void){printf("c9908 table=%s/%d\n",table[1].name,table[2].code);return 0;}
