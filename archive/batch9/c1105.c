#include <stdio.h>
struct Rect { union { struct { int left,top; }; struct { int x1,y1; }; }; union { struct { int right,bottom; }; struct { int x2,y2; }; }; };
static int area(const struct Rect *rect){return (rect->right-rect->left)*(rect->bottom-rect->top);}
int main(void){struct Rect rect={.x1=2,.y1=3,.x2=9,.y2=8};printf("c1105 rect=%d,%d\n",area(&rect),rect.left);return !(area(&rect)==35&&rect.left==2);}
