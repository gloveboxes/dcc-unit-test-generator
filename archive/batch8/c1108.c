#include <stdio.h>
struct Rect { union { struct { int left,top,right,bottom; }; int edge[4]; }; };
static int contains(const struct Rect *r,int x,int y){return x>=r->left&&x<r->right&&y>=r->top&&y<r->bottom;}
int main(void){struct Rect r={{.left=1,.top=2,.right=9,.bottom=8}};int a=contains(&r,4,4),b=contains(&r,9,4);printf("c1108 rect=%d,%d\n",a,b);return !(a&&!b);}
