#include <stdio.h>
#include <stdbool.h>
enum SettingKind { SET_INT, SET_BOOL };
struct Setting { const char *name; enum SettingKind kind; union { int number; bool enabled; }; };
static int score(const struct Setting *setting){return setting->kind==SET_INT?setting->number:(setting->enabled?1:0);}
int main(void){struct Setting a={.name="retry",.kind=SET_INT,.number=4},b={.name="echo",.kind=SET_BOOL,.enabled=true};int value=score(&a)+score(&b);printf("c1103 settings=%d,%c\n",value,b.name[0]);return !(value==5&&b.name[0]=='e');}
