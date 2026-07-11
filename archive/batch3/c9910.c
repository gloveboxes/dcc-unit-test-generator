#include <stdio.h>
enum Status{ST_NEW=10,ST_READY=20,ST_DONE=30};
static const char *label(enum Status s){switch(s){case ST_NEW:return "new";case ST_READY:return "ready";default:return "done";}}
int main(void){printf("c9910 status=%s/%d\n",label(ST_READY),ST_DONE-ST_NEW);return 0;}
