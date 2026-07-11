#include <stdio.h>
struct Rect { int left,top,right,bottom; };
static int overlap(const struct Rect *a,const struct Rect *b){int width=(a->right<b->right?a->right:b->right)-(a->left>b->left?a->left:b->left);int height=(a->bottom<b->bottom?a->bottom:b->bottom)-(a->top>b->top?a->top:b->top);return width>0&&height>0?width*height:0;}
int main(void){int area=overlap(&(struct Rect){0,0,8,6},&(struct Rect){5,2,10,5});printf("c9914 overlap=%d\n",area);return area!=9;}
