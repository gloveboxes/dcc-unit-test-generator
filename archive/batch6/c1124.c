#include <stdio.h>
struct Either{int is_left;union{int left;int right;};};
static int unwrap(struct Either e){return e.is_left?e.left:e.right;}
int main(void){struct Either a={1,{.left=8}},b={0,{.right=13}};printf("c1124 either=%d,%d\n",unwrap(a),unwrap(b));return 0;}
