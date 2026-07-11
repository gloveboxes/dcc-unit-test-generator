#include <stdio.h>
struct Box{struct{int left;int top;};struct{int right;int bottom;};};
int main(void){struct Box b;b.left=2;b.top=3;b.right=11;b.bottom=9;printf("c1109 area=%d\n",(b.right-b.left)*(b.bottom-b.top));return 0;}
