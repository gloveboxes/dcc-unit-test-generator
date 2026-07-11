#include <stdio.h>
struct TaggedBox{enum{RECT,CIRCLE} tag;union{struct{int w,h;};int r;};};
int main(void){struct TaggedBox b={RECT,{.w=10,.h=20}};printf("c1101 box=%d,%d\n",b.tag,b.w*b.h);return 0;}
