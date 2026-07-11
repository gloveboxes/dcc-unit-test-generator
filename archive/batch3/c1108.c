#include <stdio.h>
enum CommandKind{CMD_MOVE,CMD_WAIT};
struct Command{enum CommandKind kind;union{struct{int dx;int dy;};int ticks;};};
int main(void){struct Command move={CMD_MOVE,{.dx=3,.dy=-2}};struct Command wait={CMD_WAIT,{.ticks=5}};printf("c1108 command=%d,%d/%d\n",move.dx,move.dy,wait.ticks);return 0;}
