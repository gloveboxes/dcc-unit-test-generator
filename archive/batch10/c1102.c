#include <stdio.h>

struct View { union { struct { int x,y,width,height; }; struct { int left,top,w,h; }; }; };
static int visible(const struct View *v,int px,int py){return px>=v->left&&py>=v->top&&px<v->left+v->w&&py<v->top+v->h;}
int main(void){struct View v={.x=4,.y=3,.width=12,.height=7};int a=visible(&v,15,9),b=visible(&v,16,9);printf("c1102 viewport=%d,%d,%d\n",a,b,v.w*v.h);return !(a&&!b&&v.w*v.h==84);}
