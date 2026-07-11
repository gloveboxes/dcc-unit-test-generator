#include <stdio.h>
#define CAP 4
struct Log { int values[CAP]; int next; int count; };
static void append(struct Log *log,int value){log->values[log->next]=value;log->next=(log->next+1)%CAP;if(log->count<CAP)++log->count;}
static int oldest(const struct Log *log){int at=(log->next-log->count+CAP)%CAP;return log->values[at];}
int main(void){struct Log log={{0,0,0,0},0,0};int i;for(i=1;i<=6;++i)append(&log,i*10);printf("c8901 log=%d,%d\n",oldest(&log),log.count);return !(oldest(&log)==30&&log.count==4);}
