#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *pre;
  struct Node *next;
} N;

void deleteAtbeginning(N **head)
{
  if(*head==NULL)
  {
    return;
  }
  N *temp = *head;
  *head = temp->next;
  head->pre = NULL
  free(temp);
}

void delete_At_the_end(N **head)
{
  if(*head==NULL)
  {
    return;
  }
  if((*head)->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }
  N *temp = *head;
  while(temp->next->next!=NULL)
  {
    temp = temp->next;
  }
  N *last = temp->next;
  temp->next = NULL;
  if(last) last->pre = NULL;
  free(last);
  return;
}

void deleteAtpos(int pos,N **head)
{
  if(*head == NULL || pos<0)
  {
    return;
  }
  else if(pos==0)
  {
    deleteAtbeginning(head);
    return;
  }
  N *temp = *head;
  for(int i = 0;i<pos;i++)
  {
    if(temp==NULL)
    {
      printf("Invalid position\n");
      return;
    }
    temp=temp->next;
  }
  if(temp->next==NULL)
  {
    delete_At_the_end(head);
    return;
  }
  if(temp->pre)
  {
      temp->pre->next = temp->next;
  }
  if(temp->next)
  {
    temp->next->pre = temp->pre;
  }
  free(temp);
  return;
}


