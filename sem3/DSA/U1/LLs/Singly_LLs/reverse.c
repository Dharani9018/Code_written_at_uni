#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node *next;
} N;
N *CreateNewNode(int data)
{
  N *newnode = (N*)malloc(sizeof(N));
  newnode->next = NULL;
  newnode->data = data;
  return newnode;
}
void insertAtLast(N **head,int data)
{
  N *newnode =CreateNewNode(data);
  if(*head==NULL)
  {
    *head = newnode;
    return;
  }
  N *temp = *head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  return;
}
N *reverseList(N **head)
{
  N *pre = NULL,*curr = *head,*next = NULL;
  while(curr!=NULL)
  {
    next = curr->next;
    curr->next = pre;
    pre = curr;
    curr = next;
  }
  return pre;
}
void display(N **head)
{
  while(*head!=NULL)
  {
    printf("%d -> ",(*head)->data);
    *head = (*head)->next;
  }
  printf("NULL\n");
}
int main()
{
  printf("Enter size of ll: ");
  int n;
  scanf("%d",&n);
  N *head = NULL;
  for(int i = 0;i<n;i++)
  {
    int *data = (int*)malloc(sizeof(int));
    printf("Enter data %d: ",i+1);
    scanf("%d",data);
    insertAtLast(&head,*data);
  }
  printf("Before reversing: \n");
  N *temp1 = head;
  N *temp2 = head;
  N *temp3 = head;

  display(&temp1);
  printf("After reversing: \n");
  head = reverseList(&temp2);
  display(&head);
  free(head);
  head = NULL;

}
