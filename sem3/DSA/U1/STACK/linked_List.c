#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{
  int data;
  struct Node* next;
} Node;


Node *createNewnode(int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->next=NULL;
  newnode->data = data;
  return newnode;
}

void push(Node **top,int data)
{
  Node *newnode = createNewnode(data);
  if((*top)==NULL)
  {
    (*top) = newnode;
    return;
  }
  Node *temp = (*top);
  (*top) = newnode;
  newnode->next = temp;
  return;
}

void pop(Node **top)
{
  if((*top)==NULL)
  {
    printf("Stack is empty\n");
    return;
  }
  if((*top)->next!=NULL)
  {
    Node *temp = (*top);
    (*top)= (*top)->next;
    free(temp);
    temp = NULL;
    return;
  }
  free((*top));
  (*top)=NULL;
  return;
}

void display(Node **top)
{
  if((*top)==NULL)
  {
    printf("Stack is empty\n");
    return;
  }
  Node *cur = (*top);
  printf("top-> ");
  while(cur!=NULL)
  {
    printf("%d -> ",cur->data);
    cur = cur->next;
  }
  printf("NULL\n");
  return;
}
void peek(Node **top)
{
  if((*top)==NULL)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("\n%d\n",(*top)->data);
  return;
}
int main()
{
  Node *top;
  top=NULL;
  int ch,data,r;
  while(1)
  {
    printf("\n1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        printf("Enter the element: ");
        scanf("%d",&data);
        push(&top,data);
        break;

      case 3:
        display(&top);
        break;

      case 2:
        pop(&top);
        break;

      case 4:
        exit(0);
        break;

      default:printf("\nInvalid option\n");
        break;
    }
  }
  return 0;
}
