#include <stdio.h>

struct Log { int module,level,code; };
static int format(char *out,const struct Log *p){static const char *names[3]={"SYS","IO","NET"};return sprintf(out,"%s L%d E%03d",names[p->module],p->level,p->code);}
int main(void){struct Log entry={.module=2,.level=4,.code=27};char text[20];int n=format(text,&entry);printf("c9920 log=%d,%s\n",n,text);return !(n==11&&text[0]=='N'&&text[10]=='7');}
