#include <stdio.h>
static int parse_time(const char *s){return (s[0]-'0')*3600+(s[1]-'0')*600+(s[3]-'0')*60+(s[4]-'0');}
int main(void){printf("c8904 time=%d\n",parse_time("09:45"));return 0;}
