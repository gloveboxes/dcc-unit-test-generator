#include <stdio.h>
struct KeyEvent { union { struct { unsigned char code,modifiers; }; unsigned short packed; }; };
static int shifted(const struct KeyEvent *e){return (e->modifiers&1U)!=0;}
int main(void){struct KeyEvent e={{.code='A',.modifiers=1}};int actual=shifted(&e);printf("c1129 key=%d,%u\n",actual,(unsigned)e.code);return !(actual&&e.code=='A');}
