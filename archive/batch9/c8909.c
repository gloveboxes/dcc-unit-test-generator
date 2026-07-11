#include <stdio.h>
struct Pair{char key[8];char value[8];};
static int parse_pair(const char *text,struct Pair *pair){int k=0,v=0;while(*text&&*text!='='&&k<7)pair->key[k++]=*text++;if(*text!='=')return 0;pair->key[k]='\0';++text;while(*text&&v<7)pair->value[v++]=*text++;pair->value[v]='\0';return *text=='\0'&&k>0&&v>0;}
int main(void){struct Pair p;int ok=parse_pair("mode=fast",&p);printf("c8909 pair=%d,%s,%s\n",ok,p.key,p.value);return !(ok&&p.key[0]=='m'&&p.value[0]=='f');}
