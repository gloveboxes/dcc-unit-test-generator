#include <stdio.h>
#include <stdbool.h>
enum ReadingKind { TEMPERATURE, SWITCH };
struct Reading { enum ReadingKind kind; union { int tenths; bool active; }; };
static int normalize(const struct Reading *reading){return reading->kind==TEMPERATURE?reading->tenths:(reading->active?100:0);}
int main(void){struct Reading readings[3]={{.kind=TEMPERATURE,.tenths=215},{.kind=SWITCH,.active=true},{.kind=TEMPERATURE,.tenths=-5}};int total=0;for(int i=0;i<3;++i)total+=normalize(&readings[i]);printf("c1107 readings=%d\n",total);return total!=310;}
