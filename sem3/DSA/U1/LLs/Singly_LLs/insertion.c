#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  Node *next;
};
struct Node* CreateNewNode(int data)
{
  struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->next = NULL;
}

void InsertAtFirst(struct Node **head,int data)
{
  struct Node *newnode = CreateNewNode(data);
  newnode->next = *head;
  *head = newnode;
}

void InsertAtEnd(struct Node **head,int data)
{
  struct Node *newnode = CreateNewNode(data);
  if(*head == NULL)
  {
    *head = newnode;
    return;
  }
  struct Node *temp = *head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}
void InsertAtPos(struct Node **head,int data,int pos)
{
  struct Node *newnode = CreateNewNode(data);
  if(pos==0)
  {
    InsertAtFirst(head,data);
  }
  struct Node *temp = *head;
  for(int i = 0;i<pos-1;i++)
  {
    temp = temp->next;
  }
  if(temp == NULL)
  {
    printf("position out of range\n");
    free(newnode);
    return;
  }
  newnode->next = temp->next;
  temp->next = newnode;
}

void display(struct Node **head)
{
  while((*head)!=NULL)
  {
    printf("%d -> ",(*head)->data);
    head = head->next;
  }
  printf("NULL\n");
}




