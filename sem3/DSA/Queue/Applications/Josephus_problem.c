#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node *link;
}Node;
void create(Node **head)
{
  Node *temp,*rear = NULL;
  int a,ch;
  do
  {
    printf("Enter a number: ");
    scanf("%d",&a);
    temp = malloc(sizeof(Node));
    temp->link = NULL;
    temp->data = a;
    if((*head)==NULL)
    {
      *head = temp;
    }
    else
    {
      rear->link = temp;
    }
    rear = temp;
    printf("Enter 0 to disontinue: ");
    scanf("%d",&ch);
  }while(ch!=0);
  rear->link = *head;
  return;
}

int survivor(Node **head,int k)
{
  Node *p,*q;
  int i;
  p=q=*head;
  while(p->link!=p)
  {
    for(int i = 0;i<k-1;i++)
    {
      q = p;
      p = p->link;
    }
    q->link = p->link;
    printf("%d has been killed\n",p->data);
    free(p);
    p = q->link;
  }
  *head = p;
  return p->data;
}

int main()
{
  Node *head = NULL;
  int skip;
  create(&head);
  printf("Enter the number of people to be skipped: ");
  scanf("%d",&skip);
  printf("Surviver: %d\n",survivor(&head,skip));
  return 0;
}
