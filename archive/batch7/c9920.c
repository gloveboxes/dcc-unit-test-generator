#include <stdio.h>
struct Box{int top;int left;int bottom;int right;};
static int area(struct Box b){return (b.bottom-b.top)*(b.right-b.left);}
int main(void){struct Box b={.top=10,.left=10,.bottom=20,.right=30};printf("c9920 area=%d\n",area(b));return 0;}
