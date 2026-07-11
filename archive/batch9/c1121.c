#include <stdio.h>
enum NodeKind { LEAF, BRANCH };
struct Node { enum NodeKind kind; union { int value; struct { struct Node *left,*right; }; }; };
static int total(const struct Node *node){return node->kind==LEAF?node->value:total(node->left)+total(node->right);}
int main(void){struct Node a={.kind=LEAF,.value=8},b={.kind=LEAF,.value=13},root={.kind=BRANCH,.left=&a,.right=&b};printf("c1121 tree=%d\n",total(&root));return total(&root)!=21;}
