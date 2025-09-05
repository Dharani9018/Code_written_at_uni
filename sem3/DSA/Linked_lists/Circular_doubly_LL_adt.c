#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *prev;
  struct node *next;
} Node;

Node *CreateNewNode(int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->next = NULL;
  newnode->prev = NULL;
  newnode->data = data;
  return newnode;
}

void insertAtfront(Node *head,int data)
{
  Node *newnode = CreateNewNode(data);
  if(head->next==head)
  {
	head->next = newnode;
	head->prev = newnode;
	newnode->next = head;
	newnode->prev = head;
	return;
  }
  Node *temp = head->next;
  head->next = newnode;
  newnode->prev = head;
  newnode->next = temp;
  temp->prev = newnode;
  return;
}
void insertAtrear(Node *head,int data)
{
  Node *newnode = CreateNewNode(data);
  if(head->next==head)
  {
	head->next = newnode;
	head->prev = newnode;
	newnode->next = head;
	newnode->prev = head;
	return;
  }
  Node *cur = head->prev;
  newnode->prev = cur;
  newnode->next = head;
  head->prev = newnode;
  cur->next = newnode;
  return;
}

void display(Node *head)
{
  if(head->next==head)
  {
	printf("\nList is Empty\n");
	return;
  }
  Node *cur = head->next;
  printf("\n");
  while(cur!=head)
  {
	printf("%d ",cur->data);
	cur = cur->next;
  }
  printf("\n");	
}

void delete_at_front(Node *head)
{
  if(head->next==head)
  {
	printf("\nList is Empty\n");
	return;
  }
  Node *cur = head->next;
  int x = cur->data;
	head->next = cur->next;
	cur->next->prev = head;
  free(cur);
  printf("\ndeleted %d\n",x);
  return;
}	
void delete_at_rear(Node *head)
{
  if(head->next==head)
  {
	printf("\nList is Empty\n");
	return;
  } 
  Node *cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
  int x = cur->data;
  free(cur);
  printf("\nDeleted %d\n",x);
  return;
}

int main()
{
	Node *head = CreateNewNode(0);
	head->next = head;
	head->prev = head;
	int data,choice;
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
