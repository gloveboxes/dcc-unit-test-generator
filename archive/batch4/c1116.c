#include <stdio.h>
struct Node{int id;union{struct{int left;int right;};int leaf;};};
static int score(struct Node node){return node.id+(node.id?node.left+node.right:node.leaf);}
int main(void){struct Node branch={.id=3,.left=4,.right=5};struct Node leaf={.id=0,.leaf=11};printf("c1116 tree=%d,%d\n",score(branch),score(leaf));return 0;}
