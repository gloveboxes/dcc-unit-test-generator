#include <stdio.h>
struct Window{struct{int left;int top;};struct{int right;int bottom;};};
static int width(struct Window w){return w.right-w.left;}
int main(void){struct Window w={.left=3,.top=4,.right=19,.bottom=12};printf("c1101 window=%d,%d\n",width(w),w.bottom-w.top);return 0;}
