#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} NODE;

void Insert(NODE **root, int num) {
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = num;
  newnode->left = newnode->right = NULL;

  if (*root == NULL) {
    *root = newnode;
    return;
  }

  NODE *pre = NULL, *cur = *root;
  while (cur != NULL) {
    pre = cur;
    if (num < cur->data)
      cur = cur->left;
    else if (num > cur->data)
      cur = cur->right;
    else {
      free(newnode);  // duplicates not allowed
      return;
    }
  }

  if (num < pre->data)
    pre->left = newnode;
  else
    pre->right = newnode;
}

void Preorder(NODE *root) {
  if (root == NULL) return;
  printf("%d\t", root->data);
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(NODE *root) {
  if (root == NULL) return;
  Inorder(root->left);
  printf("%d\t", root->data);
  Inorder(root->right);
}

void Postorder(NODE *root) {
  if (root == NULL) return;
  Postorder(root->left);
  Postorder(root->right);
  printf("%d\t", root->data);
}

void Delete(NODE **root, int key) {
  if (*root == NULL) {
    printf("\nEmpty tree\n");
    return;
  }

  NODE *cur = *root, *parent = NULL;

  while (cur != NULL && cur->data != key) {
    parent = cur;
    if (key < cur->data)
      cur = cur->left;
    else
      cur = cur->right;
  }

  if (cur == NULL) {
    printf("\nElement doesn't exist\n");
    return;
  }

  int x = cur->data;
  NODE *succParent = NULL, *succ = NULL;

  // Node with 2 children
  if (cur->left != NULL && cur->right != NULL) {
    succParent = cur;
    succ = cur->right;
    while (succ->left != NULL) {
      succParent = succ;
      succ = succ->left;
    }
    cur->data = succ->data;  // Replace data
    cur = succ;
    parent = succParent;
  }

  NODE *child = (cur->left != NULL) ? cur->left : cur->right;

  if (parent == NULL) {  // Deleting root
    *root = child;
    free(cur);
    printf("\nNode %d deleted\n", x);
    return;
  }

  if (cur == parent->left)
    parent->left = child;
  else
    parent->right = child;

  free(cur);
  printf("\nNode %d deleted\n", x);
}

int main() {
  NODE *root = NULL;
  int ch, num;

  while (1) {
    printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n6.Exit\n");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &num);
        Insert(&root, num);
        break;

      case 2:
        printf("\nPreorder Traversal\n");
        Preorder(root);
        break;

      case 3:
        printf("\nInorder Traversal\n");
        Inorder(root);
        break;

      case 4:
        printf("\nPostorder Traversal\n");
        Postorder(root);
        break;

      case 5:
        printf("\nEnter the element to delete: ");
        scanf("%d", &num);
        Delete(&root, num);
        break;

      case 6:
        return 0;

      default:
        printf("\nInvalid Option\n");
    }
  }
}

