#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
  int data;
  struct tree *left,*right;
} Btree;

Btree *createnode(int data)
{
  Btree *node = malloc(sizeof(Btree));
  node->data = data;
  node->left=node->right=NULL;
  return node;
}

void preorder_traversal(Btree *root)
{
  Btree *node = root;
  if(node==NULL)
  {
    return;
  }
  printf("%d ",node->data);
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}
void inorder_traversal(Btree *root)
{

}
int main()
{
  Btree *root = createnode(10);
  root->right = createnode(20);
  root->left = createnode(30);
  root->left->left = createnode(40);
  root->left->right = createnode(50);
  root->left->left->left = createnode(0);
  root->right->left = createnode(8);
  root->right->left->right = createnode(6);
  preorder_traversal(root);
  printf("\n");
  return 0;
}
