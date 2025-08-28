#include<stdio.h>
#include<stdlib.h>
void display(struct Node **head)
{
  while((*head)!=NULL)
  {
    printf("%d -> ",(*head)->data);
    head = head->next;
  }
  printf("NULL\n");
}

void deleteFromFirst(struct Node **head)
{
  if(*(head)==NULL)
  {
    return;
  }
  struct Node *temp = *(head);
  *(head) = temp->next;
  free(temp);
}

void deleteFromEnd(struct Node **head)
{
  if(*(head)==NULL)
  {
    printf("List is Empty");
    return;
  }
  struct Node *temp = *head;
  if(temp->next==NULL)
  {
    free(temp);
    *head = NULL;
    return; 
  }
  while(temp->next->next!=NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next=NULL;
}

void deleteAtPos(struct Node **head,int pos)
{
  if(pos==0)
  {
    deleteFromFirst(head);
    return;
  }
  if(*head==NULL)
  {
    printf("List is Empty. \n");
    return;
  }
  struct Node *temp = *head;
  for(int i = 0;i<pos;i++)
  {
    temp = temp->next;
  }
  if(temp==NULL || temp->next==NULL)
  {
    printf("Invalid position.\n");
    return;
  }
  struct Node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
  return;
}
