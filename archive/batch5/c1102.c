#include <stdio.h>
struct Rect{struct{int left;int top;};struct{int right;int bottom;};};
int main(void){struct Rect r={.left=2,.top=3,.right=11,.bottom=9};printf("c1102 rect=%d\n",(r.right-r.left)*(r.bottom-r.top));return 0;}
