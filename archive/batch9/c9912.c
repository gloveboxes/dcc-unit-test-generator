#include <stdio.h>
#include <stdbool.h>
enum Phase { IDLE, ACTIVE, FAULT };
static enum Phase advance(enum Phase phase,bool start,bool error){if(error)return FAULT;if(phase==IDLE&&start)return ACTIVE;if(phase==ACTIVE&&!start)return IDLE;return phase;}
int main(void){enum Phase phase=IDLE;phase=advance(phase,true,false);phase=advance(phase,true,true);printf("c9912 phase=%d\n",(int)phase);return phase!=FAULT;}
