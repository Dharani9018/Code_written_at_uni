#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef struct Node
{
  int data;
  struct Node *pre;
  struct Node *next;
} N;

//Creating a node
N *createNode(int data)
{
  N *newnode = (N*)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  newnode->pre = NULL;
  return newnode;
}

//forward traversal
void forward_traversal(N** head)
{
  N *curr = *head;
  while(curr!=NULL)
  {
    printf("%d -> ",curr->data);
    curr = curr->next;
    count++;
  }
  printf("NULL\n");
}

//  Function to reverse a doubly linked list
void reverseDLL(N ** head) 
{
    // code here
    if((*head)==NULL || (*head)->next==NULL)
    {
        return;
    }
    N *cur= (*head),*temp=NULL;
    
    while(cur!=NULL)
    {
            temp = cur->pre;
            cur->pre = cur->next;
            cur->next = temp;
            cur = cur->pre;
    }
  if(temp!=NULL)
    (*head) = temp->pre; 
  return;
}

//forward_traversal using recursion:
void forward_traversal_using_recursion(N** head)
{
  if(*head==NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("%d -> ",(*head)->data);
  forward_traversal_using_recursion(&((*head)->next));
}

//backward traversal
void backward_traversal(N **tail)
{
  N *curr1 = *tail;
  while(curr1!=NULL)
  {
    printf("%d -> ",curr1->data);
    curr1 = curr1->pre;
  }
  printf("NULL\n");
}

void backward_traversal_using_recursion(N **tail)
{
  if(*tail==NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("%d -> ",(*tail)->data);
  backward_traversal_using_recursion(&((*tail)->pre));
}


int main()
{ 
  struct Node* head = createNode(1);
  struct Node* second = createNode(2);
  struct Node* third = createNode(3);
  head->next = second;
  head->pre = NULL;
  second->next = third;
  second->pre = head;
  third->pre = second;
  third->next = NULL;
  printf("forward traversal: \n");
  forward_traversal(&head);
  printf("forward_traversal_using_recursion:\n");
  forward_traversal_using_recursion(&head);
  printf("backward traversal: \n");
  backward_traversal(&third);
  printf("backward_traversal_using_recursion:\n");
  backward_traversal_using_recursion(&third);
  printf("count: %d\n",count);
  reverseDLL(&head);
  forward_traversal(&head);

  return 0;
}
//iterative:
//Time Complexity: O(n), where n is the number of nodes in the linked list
//Auxiliary Space: O(1)

//recursive:
//Time Complexity: O(n), where n is the number of nodes in the linked list
//Auxiliary Space: O(n)


