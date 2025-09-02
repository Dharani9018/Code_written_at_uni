//sll/

/*insertion*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} N;

typedef struct List
{
  N *head;
} list;

void initialise_list(list *l)
{
  l->head = NULL;
  return;
}

N *createNewnode(int data)
{
  N *newnode = malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void insertAtfront(int data,list *l)
{
  N *newnode = createNewnode(data);
  if(l->head==NULL)
  {
    l->head = newnode;
    return;
  }
  newnode->next = l->head;
  l->head = newnode;
  return;
}

void insertAtrear(int data,list *l)
{
  N *newnode = createNewnode(data);
  if(l->head==NULL)
  {
    l->head = newnode;
    return;
  }
  N *temp = l->head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  return;
}

void delete_at_front(list *l)
{
  if(l->head==NULL)
  {
    printf("List is empty");
    return ;
  }
  N *temp = l->head;
  l->head = temp->next;
  printf("Deleted %d\n",temp->data);
  free(temp);
  temp = NULL;
  return; 
}

void delete_at_rear(list *l)
{
  if(l->head==NULL)
  {
    printf("Empty list\n");
    return;
  }
  N *cur = l->head;
  N *pre = NULL;
  while(cur->next!=NULL)
  {
    pre = cur;
    cur = cur->next;
  }
  pre = NULL;
  printf("Deleted %d\n",cur->data);
  free(cur);
  cur = NULL;
  return;
}

void insert_at_pos(int ele, int pos, list *l)
{
  N *pre=NULL;
  N *cur = l->head;
  N *temp = malloc(sizeof(N));
  temp->next = NULL;
  temp->data = ele;

  int i = 1;
  while(cur!=NULL && i<pos)
  {
    pre = cur;
    cur = cur->next;
    i++;
  }
  if(cur!=NULL)
  {
    if(pre==NULL)
    {
      l->head = temp;
      temp->next = cur;
    }
    else
    {
      pre->next = temp;
      temp->next = cur;
    }
  }
  else
  {
    if(pos==i)
    {
      pre->next=temp;
    }
    else
    {
      printf("Invalid position\n");
    }
  }
  return;
}

void insert_sort_list(int ele, list *l)
{
  N *newnode = malloc(sizeof(N));
  newnode->next = NULL;
  newnode->data = ele;
  if(l->head==NULL)
  {
    l->head = newnode;
    return;
  }
  N *cur = l->head;
  N *pre = NULL;
  while(cur->data<newnode->data && cur->next!=NULL)
  {
    pre = cur;
    cur = cur->next;
  }
  if(pre==NULL)
  {
    l->head = newnode;
    newnode->next = cur;
    return;
  }
  if(cur->data<newnode->data && cur->next==NULL)
  {
    cur->next = newnode;
    return;
  }
  pre->next = newnode;
  newnode->next = cur;
  return;
}

int count(list *l)
{
  int count = 0;
  N *temp = l->head;
  while(temp!=NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

void display(list *l)
{
  if(l->head==NULL)
  {
    printf("Enpty list\n");
    return;
  }
  N *temp = l->head;
  while(temp!=NULL)
  {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
  return;
}


int main()
{
  list L;
  initialise_list(&L);
  int data,choice,pos;
  while(1)
  {
    printf("\n");
    printf("1: Insert at front\n2:Insert At rear\n3:display\n4:delete at front\n5:delete at rear\n6:Insert at position\n7:insert at correct position in ascending\n8:exit\n");
    scanf("%d",&choice);
    switch (choice) 
    {
      case 1:
        printf("Enter data: ");
        scanf("%d",&data);
        insertAtfront(data,&L);
        break;

      case 2:
        printf("Enter data: ");
        scanf("%d",&data);
        insertAtrear(data,&L);
        break;

      case 3:
        display(&L);
        break;
        
      case 4:
        delete_at_front(&L);
        break;

      case 5:
        delete_at_rear(&L);
        break;

      case 6:
        printf("Enter data: ");
        scanf("%d",&data);
        printf("Enter position: ");
        scanf("%d",&pos);
        insert_at_pos(data,pos,&L);
        break;

      case 7:
        printf("Enter data: ");
        scanf("%d",&data);
        insert_sort_list(data,&L);
        break;

      case 8:
        exit(0);

      default:
        printf("Invalid choice\n");
        break;  
    }
  }
  return 0;


}


