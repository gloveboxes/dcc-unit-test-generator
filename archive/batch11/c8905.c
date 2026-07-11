#include <stdio.h>
struct Node{int key;struct Node *left,*right;};
static struct Node nodes_g[6];
static int used_g;
static struct Node *root_g;
static void insert_g(int key){
    struct Node *n;
    struct Node *cur;
    n = &nodes_g[used_g];
    used_g = used_g + 1;
    n->key = key;
    n->left = 0;
    n->right = 0;
    if(!root_g){root_g=n;return;}
    cur=root_g;
    while(1){
        if(key<cur->key){if(!cur->left){cur->left=n;return;}cur=cur->left;}
        else{if(!cur->right){cur->right=n;return;}cur=cur->right;}
    }
}
static int inorder(const struct Node *node,int out[],int at){if(!node)return at;at=inorder(node->left,out,at);out[at++]=node->key;return inorder(node->right,out,at);}
int main(void){int out[6];int keys[6]={5,3,7,1,4,8},i;used_g=0;root_g=0;for(i=0;i<6;++i)insert_g(keys[i]);inorder(root_g,out,0);printf("c8905 bst=%d,%d,%d\n",out[0],out[2],out[5]);return !(out[0]==1&&out[2]==4&&out[5]==8);}
