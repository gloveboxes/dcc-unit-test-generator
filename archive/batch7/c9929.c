#include <stdio.h>
struct Config{int id;int flags;};
static int get_flags(struct Config c){return c.flags;}
int main(void){printf("c9929 cfg=%d\n",get_flags((struct Config){.id=1,.flags=0x3f}));return 0;}
