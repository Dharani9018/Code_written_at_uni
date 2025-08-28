#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *pre;
} N;

N *createNewNode(int data)
{
  N *newnode = (N*)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  newnode->pre = NULL;
  return newnode;
}

void insert_At_First(N **head,int data)
{
  N *newnode = createNewNode(data);
  if((*head)==NULL)
  {
    (*head)=newnode;
    (*head)->next = *head;
    (*head)->pre = *head;
    return;
  }
  newnode->next = (*head);
  newnode->pre = (*head)->pre;
  (*head)->pre->next = newnode;
  (*head)->pre = newnode;
  (*head) = newnode;
  return;
}

void insert_At_last(N **head,int data)
{
  if((*head)==NULL)
  {
    insert_At_First(head,data);
    return;
  }
  N *newnode = createNewNode(data);
  N *last = (*head)->pre;
  last->next = newnode;
  newnode->next = (*head);
  (*head)->pre = newnode;
  newnode->pre = last;
  return;
}

void insert_At_position(N **head,int data,int pos)
{
  if((*head)==NULL)
  {
    printf("\nEmpty lsit\n");
    return;
  }
  if(pos==1)
  {
    insert_At_First(head,data);
    return;
  }
  N *temp = *head;
  N *newnode = createNewNode(data);
  for(int i = 1;i<pos-1;i++)
  {
    if(temp->next==(*head))
    {
      printf("\ninvalid position\n");
      return;
    }
    temp = temp->next;
  }

  newnode->next = temp->next;
  temp->next->pre = newnode;
  newnode->pre = temp;
  temp->next = newnode;
  return;

}
void delete_At_front(N **head)
{
  if((*head)==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  N *last = (*head)->pre;
  N *first = (*head);
  last->next = first->next;
  first->next->pre = last;
  (*head) = first->next;
  free(first);
  return;
}

void delete_At_last(N **head)
{
  if((*head)==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  N *last = (*head)->pre;
  N *first = (*head);
  last->pre->next = first;
  first->pre = last->pre;
  free(last);
  return;
}

void delete_at_pos(N **head,int pos)
{
  if((*head)==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  if(pos==1)
  {
    delete_At_front(head);
    return;
  }
  N *temp = (*head);
  for(int i = 1;i<pos-1;i++)
  {
    if(temp==(*head)->pre)
    {
      printf("\nInvalid position\n");
      return;
    }
    temp=temp->next;
  }
  N *del = temp->next;
  temp->next = del->next;
  del->next->pre = temp->next;
  free(del);
  return;
}


void display(N **head)
{
  if((*head)==NULL)
  {
    printf("\nEmpty list\n");
    return;
  }
  N *temp = *head;
  printf("\nhead->");
  while(temp->next!=(*head))
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("%d->head\n",temp->data);
  return;
}

int main()
{
  N *head = NULL;
  int data,choice,pos;
  while(1)
  {
    printf("\n1:display\n2:insert_At_First\n3:insert_At_last\n4:insert_At_position\n5:delete_At_front\n6:delete_At_last\n7:delete_at_pos\n8:Exit\n");
    scanf("%d",&choice);
    switch (choice) 
    {
      case 1:
      display(&head);
      break;

      case 2:
      printf("Enter data: ");
      scanf("%d",&data);
      insert_At_First(&head,data);
      break;

      case 3:
      printf("Enter data: ");
      scanf("%d",&data);
      insert_At_last(&head,data);
      break;

      case 4:
      printf("Enter data: ");
      scanf("%d",&data);
      printf("Enter position from 1: ");
      scanf("%d",&pos);
      insert_At_position(&head,data,pos);
      break;

      case 5:
      delete_At_front(&head);
      break;

      case 6:
      delete_At_last(&head);
      break;

      case 7:
      printf("Enter position from 1: ");
      scanf("%d",&pos);
      delete_at_pos(&head,pos);
      break;

      case 8:
      exit(0);
      break;

      default:
      printf("invalid choice!\n");
      break;
    }
  }
}

