#include<stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct Node
{
  struct Node *next;
  struct Node *pre;
  int data;
} N;

N *createNewNode(int data)
{
  N *newnode = (N*)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  newnode->pre = NULL;
  return newnode;
}
int forward_traversal(N** head)
{
  int count = 0;
  N *curr = *head;
  while(curr!=NULL)
  {
    curr = curr->next;
    count++;
  }
  return count;
}
void display(N** head)
{
  N *curr = *head;
  while(curr!=NULL)
  {
    printf("%d -> ",curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
  return;
}


void insertAtFirst(int data,N **head)
{
  N *newnode = createNewNode(data);
  if(*head==NULL)
  {
    *head = newnode;
    return;
  }
  N *temp = *head;
  *head = newnode;
  (*head)->next = temp;
  temp->pre = *head;
  return;
}

void insertAtLast(int data,N **head)
{
  N *t = *head;
  if(t==NULL)
  {
    insertAtFirst(data,head);
    return;
  }
  while(t->next!=NULL)
  {
    t = t->next;
  }
  t->next = createNewNode(data);
  t->next->pre = t;
  return;
}

void insertAtPosition(int data, N **Node, int pos)
{
    if (*Node == NULL && pos == 0) {
        *Node = createNewNode(data);
        return;
    }

    int count = forward_traversal(Node);

    if (pos == 0) 
    {
        insertAtFirst(data, Node);
    } 
    else if (pos == count) 
    {
        insertAtLast(data, Node);
    } 
    else if (pos > 0 && pos < count) 
    {
        N *temp = *Node;
        for (int i = 0; i < pos - 1; i++) 
        {
            if (temp == NULL) 
            {
                printf("Invalid position\n");
                return;
            }
            temp = temp->next;
        }

        N *nextNode = temp->next;
        N *newNode = createNewNode(data);
        temp->next = newNode;
        newNode->pre = temp;
        newNode->next = nextNode;

        if (nextNode != NULL)
        { 
            nextNode->pre = newNode;
        }
    }
    else 
    {
        printf("Invalid position\n");
    }
}
int main()
{
  srand(time(0));
  int n = 0;
  int x = 0;
  int data = 0;
  N *head = NULL;
  printf("1:Generate random dll\n2:Create new\n");
  scanf("%d",&n);
  switch (n)
  {
    case 1:
    {
        x = (rand())%15 + 1;
        for(int i = 0;i<x;i++)
        {
          data = (rand())%100;
          insertAtLast(data,&head);
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
          insertAtLast(data,&head);
      }
      break;
    }
    default:
      printf("Invalid option\n");
      return 0;
  }
  printf("DLL:\n");
  display(&head);
  int pos = 0;
  printf("Enter the position to insert the data: ");
  scanf("%d",&pos);
  printf("Data: ");
  scanf("%d",&data);
  insertAtPosition(data,&head,pos);
  display(&head);
  return 0;
}

