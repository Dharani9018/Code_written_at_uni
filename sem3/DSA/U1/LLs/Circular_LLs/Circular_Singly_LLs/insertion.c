#include<stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct Node
{
  int data;
  struct Node* next;
} N;

N *createNewnode(int data)
{
  N *newnode = (N*)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void InsertAtTheBeginning(int data,N **last)
{
  N *newnode = createNewnode(data);
  if((*last)==NULL)
  {
    (*last) = newnode;
    (*last)->next = *last;
    return;
  }
  N *temp = (*last)->next;
  (*last)->next = newnode;
  newnode->next = temp;
  return;
}

void InsertAtTheEnd(int data,N **last)
{
  if((*last)==NULL)
  {
    InsertAtTheBeginning(data,last);
    return;
  }
  N *newnode = createNewnode(data);
  N *temp = (*last)->next;
  (*last)->next = newnode;
  newnode->next=temp;
  *last = newnode;
  return;
}

void insertAtposition(int data,N **last,int pos)
{

  if((*last)==NULL || (*last)->next==NULL || pos<=0)
  {
    printf("INVALID\n");
    return;
  }
  else if(pos==1)
  {
    InsertAtTheBeginning(data,last);
    return;
  }
  N *newnode = createNewnode(data);
  N *temp = (*last)->next;
  for(int i = 1;i<pos-1; i++)
  {
    temp = temp->next;
    if(temp==(*last)->next)
    {
      printf("Invalid position\n");
      return;
    }
  }
  N *temp2 = temp->next;
  temp->next = newnode;
  newnode->next = temp2;
  return;
}
void display(N **last)
{
  if(*last==NULL || (*last)->next==NULL)
  {
    return;
  }
  N *temp = (*last)->next;
  printf("head-> ");
  do 
  {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }while(temp!=(*last)->next);
  printf("head\n");
}

int main()
{
  srand(time(0));
  int n = 0;
  int x = 0;
  int data = 0;
  N *last = NULL;
  printf("1:Generate random circular singly ll\n2:Create new\n");
  scanf("%d",&n);
  switch (n)
  {
    case 1:
    {
        x = (rand())%15 + 1;
        for(int i = 0;i<x;i++)
        {
          data = (rand())%100;
          InsertAtTheEnd(data,&last);
        }
        break;
    }
    case 2:
    {
      printf("Enter the number of nodes: ");
      scanf("%d",&x);
      for(int i = 0;i<x;i++)
      {
          printf("Enter data-%d: ",i+1);
          scanf("%d",&data);
          InsertAtTheEnd(data,&last);
      }
      break;
    }
    default:
      printf("Invalid option\n");
      return 0;
  }
  printf("Circular Singly ll:\n");
  display(&last);
  int pos = 0;
  printf("Enter the position to insert the data: ");
  scanf("%d",&pos);
  printf("Data: ");
  scanf("%d",&data);
  insertAtposition(data,&last,pos);
  printf("After insertion: \n");
  display(&last);
  return 0;
}




