#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data,lthread,rthread;
  struct Node *right,*left;
} NODE;

typedef struct tree
{
  NODE *root;
} tree;

tree *init()
{
  tree *temp = malloc(sizeof(tree));
  temp->root = NULL;
}
void *Create(tree *ptr,int data)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  newnode->lthread = newnode->rthread = 1;
  if(ptr->root == NULL)
    ptr->root = newnode;
    return;
  NODE *cur = ptr->root;
  while(1)
  {
    if(data<cur->data)
    {
      if(lthread==0)
      {
        cur = cur->left;
      }
      else
      {
        break;
      }
    }
    else
    {
      if(cur->rthread==0)

    }
  }

}
int main()
{
  tree *t = init();
  int ch,ele;
  while(1)
  {
    printf("\n1.Create\n2.inorder\n3.exit");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Create(t,ele);
        break;
      case 2:
        inorder(t);
        break;
      case 3:
        return 0;
      default:
        printf("\nInvalid choice\n");
    }
  }
}
