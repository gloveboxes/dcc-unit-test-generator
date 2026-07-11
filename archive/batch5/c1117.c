#include <stdio.h>
struct Node{int id;union{struct{int left;int right;};int leaf;};};
int main(void){struct Node n={.id=3,.left=4,.right=5};printf("c1117 node=%d\n",n.id+n.left+n.right);return 0;}
