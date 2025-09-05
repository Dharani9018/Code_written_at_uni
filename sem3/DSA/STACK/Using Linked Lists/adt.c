#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *link;
} Node;

void push(Node **top,int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->link = NULL;
  newnode->data = data;
  if(*top==NULL)
  {
    *top=newnode;
    return;
  }
  Node *temp = (*top)->link;
  newnode->link = *top;
  (*top) = newnode;

  return;
}

void pop(Node **top)
{
  if(*top==NULL)
  {
    printf("\nUnderflow\n");
    return;
  }
  Node *temp = *top;
  (*top) = (*top)->link;
  int x = temp->data;
  free(temp);
  printf("\nDeleted %d",x);
  return;
}

void display(Node **top)
{
  if(*top==NULL)
  {
    printf("\nUnderflow\n");
    return;
  }
  Node *cur = *top;
  while(cur!=NULL)
  {
    printf("%d\t",cur->data);
    cur = cur->link;
  }
  return;
}

int main()
{
  Node *top = NULL;
  int ele,ch;
  while(1)
  {
    printf("\n1.push\n2.pop\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter the data: ");
        scanf("%d",&ele);
        push(&top,ele);
        break;

      case 2:
        pop(&top);
        break;

      case 3:
        display(&top);
        break;

      case 4:
        return 0;

      default: printf("\nInvalid choice\n");
        break;
    }
  }
} 
