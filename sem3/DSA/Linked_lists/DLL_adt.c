#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
  int data;
  struct Node *next;
  struct Node *pre;
} N;

typedef struct List
{
  int no_of_nodes;
  N *head;
} Dlist;

Dlist *initialize()
{
  Dlist *list = malloc(sizeof(Dlist));
  list->no_of_nodes=0;
  list->head = NULL;
  return list;
}

void insert_at_front(Dlist *ptr, int data)
{
  N *newnode = malloc(sizeof(N));
  newnode->next=newnode->pre=NULL;
  newnode->data = data;
  if(ptr->head==NULL)
  {
    ptr->head = newnode;
    ptr->no_of_nodes++;

    return;
  }
  newnode->next = ptr->head;
  ptr->head->pre = newnode;
  ptr->head = newnode;
  ptr->no_of_nodes++;

  return;
}

void insert_at_rear(Dlist *ptr, int data)
{
  N *newnode = malloc(sizeof(N));
  newnode->next=newnode->pre=NULL;
  newnode->data = data;
  if(ptr->head==NULL)
  {
    ptr->head = newnode;
    ptr->no_of_nodes++;
    return;
  }

  N *cur = ptr->head;
  while(cur->next!=NULL)
  {
    cur = cur->next;
  }
  cur->next = newnode;
  newnode->pre = cur;
  ptr->no_of_nodes++;
  return;
}

void display(Dlist *ptr)
{
  if(ptr->head==NULL)
  {
    printf("\nEmpty list\n");
    return;
  }
  N *temp = ptr->head;
  while(temp!=NULL)
  {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
  return;
}

void delete_at_front(Dlist *ptr)
{
  if(ptr->head==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  if(ptr->head->next==NULL)
  {
    printf("deleted %d\n",ptr->head->data);
    free(ptr->head);
    ptr->head=NULL;
    return;
  }
  N *temp = ptr->head;
  temp->next->pre = NULL;
  ptr->head = temp->next;
  printf("deleted %d\n",ptr->head->data);
  free(temp);
  temp=NULL;
  return;
}
void delete_at_rear(Dlist *ptr)
{
  if(ptr->head==NULL)
  {
    printf("\nList is empty\n");
    return;
  }

  if(ptr->head->next==NULL)
  {
    printf("deleted %d\n",ptr->head->data);
    free(ptr->head);
    ptr->head=NULL;
    return;
  }

  N *cur = ptr->head;
  while(cur->next!=NULL)
  {
    cur = cur->next;
  }
  cur->pre->next = NULL;
  printf("deleted %d\n",cur->data);
  free(cur);
  cur = NULL;
  return;

}



int main()
{
  Dlist *List = initialize();
  int ch,pos,ele;
  while(1)
  {
    printf("\n1.display\n2.insert_at_front\n3.insert_at_rear\n4.delete_at_rear\n5.delete_at_front\n6.Exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        display(List);
        break;

      case 2:
        printf("Enter the element: ");
        scanf("%d",&ele);
        insert_at_front(List,ele);
        break;

      case 3:
        printf("Enter the element: ");
        scanf("%d",&ele);
        insert_at_rear(List,ele);
        break;

      case 4:
        delete_at_rear(List);
        break;

      case 5:
        delete_at_front(List);
        break;

      case 6:
        exit(0);

      default: printf("invalid choice\n");
      break;


    }
  }
  return 0;
}
