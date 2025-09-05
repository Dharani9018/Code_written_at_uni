#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *link;
} Node;

Node *CreateNewNode(int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->link = NULL;
  newnode->data = data;
  return newnode;

}
void insertAtfront(Node *head,int data)
{
  Node *newnode = CreateNewNode(data);
  if(head->link==head)
  {
    head->link = newnode;
    newnode->link = head;
    return;
  }
  Node *temp = head->link;
  head->link = newnode;
  newnode->link = temp;
  return;
}

void insertAtrear(Node *head,int data)
{
  Node *newnode = CreateNewNode(data);
  if(head->link==head)
  {
    head->link = newnode;
    newnode->link = head;
    return;
  }
  Node *cur = head->link;
  while(cur->link!=head)
  {
    cur = cur->link;
  }
  cur->link = newnode;
  newnode->link = head;
  return;
}
void display(Node *head)
{
  if(head->link==head)
  {
    printf("\nList is Empty\n");
    return;
  }
  Node *cur = head->link;
  printf("\n");
  while(cur!=head)
  {
    printf("%d\t",cur->data);
    cur = cur->link;
  }
  return;
}

void delete_at_front(Node *head)
{
  if(head->link==head)
  {
    printf("\nList is Empty\n");
    return;
  }
  Node *cur = head->link;
  int x = cur->data;
  head->link = cur->link;
  free(cur);
  printf("\ndeleted %d\n",x);
  return;
}

void delete_at_rear(Node *head)
{
  if(head->link==head)
  {
    printf("List is Empty");
    return;
  } 
  Node *cur = head->link,*pre=head;
  while(cur->link!=head)
  {
    pre=cur;
    cur = cur->link;
  }
  pre->link = head;
  int x = cur->data;
  free(cur);
  printf("\nDeleted %d\n",x);
  return;
}

int main()
{
  int data,choice,pos;
  Node *head=CreateNewNode(0);
  head->link = head;
  while(1)
  {
    printf("\n");
    printf("1: Insert at front\n2:Insert At rear\n3:display\n4:delete at front\n5:delete at rear\n6:exit\n");
    scanf("%d",&choice);
    switch (choice) 
    {
      case 1:
        printf("Enter data: ");
        scanf("%d",&data);
        insertAtfront(head,data);
        break;

      case 2:
        printf("Enter data: ");
        scanf("%d",&data);
        insertAtrear(head,data);
        break;

      case 3:
        display(head);
        break;
        
      case 4:
        delete_at_front(head);
        break;

      case 5:
        delete_at_rear(head);
        break;
        
      case 6:
        return 0;

      default:
        printf("Invalid choice\n");
        break;  
    }
  }
  return 0;
}


