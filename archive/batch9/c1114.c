#include <stdio.h>
enum CommandKind { MOVE, DELAY };
struct Command { enum CommandKind kind; union { struct { int dx,dy; }; int ticks; }; };
static int cost(const struct Command *command){return command->kind==MOVE?(command->dx<0?-command->dx:command->dx)+(command->dy<0?-command->dy:command->dy):command->ticks;}
int main(void){struct Command queue[3]={{.kind=MOVE,.dx=3,.dy=-2},{.kind=DELAY,.ticks=4},{.kind=MOVE,.dx=-1,.dy=5}};int total=0;for(int i=0;i<3;++i)total+=cost(&queue[i]);printf("c1114 commands=%d\n",total);return total!=15;}
