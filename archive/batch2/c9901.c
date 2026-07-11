#include <stdio.h>
static const char *names[4]={[0]="zero",[2]="two",[3]="three"};
int main(void){printf("c9901 designated=%s/%s/%s\n",names[0],names[2],names[3]);return 0;}
