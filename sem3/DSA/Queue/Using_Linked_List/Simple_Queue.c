#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *link;
} Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
} Queue;

Queue *Initialize()
{
  Queue *q = malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void Enqueue(Queue *q,int ele)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->data = ele;
  newnode->link = NULL;
  if(q->front==NULL && q->rear==NULL)
  {
    q->front=q->rear=newnode;
    return;
  }
  q->rear->link = newnode;
  q->rear = newnode;
  return;
}

void Dequeue(Queue *q)
{
  if(q->front==NULL)
  { 
    printf("\nUnderflow\n");
    return;
  }

  int x = q->front->data;
  if(q->front->link==NULL)
  {
    free(q->front);
    q->front=q->rear=NULL;
  }
  else
  {
    Node *cur = q->front;
    q->front = q->front->link;
    free(cur);
  }
  printf("\ndeleted: %d",x);
  return;
}
void display(Queue *q)
{
  if(q->rear==NULL)
  {
    printf("\nUnderflow\n");
    return;
  }
  
  Node *cur = q->front;
  while(cur!=NULL)
  {
    printf("%d\t",cur->data);
    cur = cur->link;
  }
  return;
}
int main()
{
  Queue *q = Initialize();
  int ch,ele;
  while (1) 
  {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Enqueue(q,ele);
        break;
      case 2:
        Dequeue(q);
        break;
      case 3:
        display(q);
        break;
      case 4:
        return 0;
        break;
      default:
        printf("\nInvalid choice\n");
        break;
    }
  }
}
