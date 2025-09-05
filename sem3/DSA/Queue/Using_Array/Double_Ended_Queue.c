#include<stdio.h>

#define MAX 5

//Can act as stack or queue.
void Insert_At_front(int *q,int *front,int *rear,int ele)
{
  if((*front==0 && *rear==MAX-1) || (*front == *rear + 1))
  {
    printf("\nOverflow\n");
    return;
  }
  if(*front == -1 && *rear == -1)
  {
    *front = *rear = 0;
  }
  else if(*front == 0)
  {
    *front = MAX-1;
  }
  else
  {
    *front = *front - 1;
  }
  q[*front] = ele;
  return;
}
void Delete_at_front(int *q,int *front,int *rear)
{
  if(*front == -1 && *rear == -1)
  {
    printf("\nUnderflow\n");
    return;
  }

  if(*front == *rear)
  {
    printf("\nDeleted: %d\n",q[*front]);
    *rear=*front=-1;
    return;
  }
  printf("\nDeleted: %d\n",q[*front]);
  *front = ((*front)+1)%MAX;
}

void Insert_At_rear(int *q,int *front,int *rear,int ele)
{
  if((*front==0 && *rear == MAX-1) || (*front==*rear + 1))
  {
    printf("\nOverflow\n");
    return;
  }

  if(*front==-1 && *rear==-1)
  {
    *front=*rear=0;
  }
  else if(*rear==MAX-1)
  {
    *rear = 0;
  }
  else
  {
    *rear = *rear + 1;
  }
  q[*rear] = ele;
  return;
}

void Delete_at_rear(int *q,int *front,int *rear)
{
  if(*front==-1 && *rear==-1)
  {
    printf("\nUnderflow\n");
    return;
  }
  int x = q[*rear];
  if(*rear==*front)
  {
    *rear=*front=-1;
  }
  else if(*rear==0)
  {
    *rear = MAX - 1;
  }
  else
  {
    *rear = *rear - 1;
  }
  printf("\nDeleted: %d\n",x);
  return;
}

void display(int *q,int front,int rear)
{
  if(front==-1 && rear==-1)
  {
    printf("\nUnderflow\n");
    return;
  }
  int i = front;
  while(i!=rear)
  {
    printf("%d\t",q[i]);
    i = (i+1)%MAX;
  }
  printf("%d\n",q[rear]);

}

int main()
{
  int q[5],front=-1,rear=-1,ch,ele;

while (1) 
  {
    printf("\n1.Insert_At_front\n2.Delete_at_front\n3.Display\n4.Insert_At_rear\n5.Delete_at_rear\n6.Exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Insert_At_front(q,&front,&rear,ele);
        break;
      case 2:
        Delete_at_front(q,&front,&rear);
        break;
      case 3:
        display(q,front,rear);
        break;
      case 6:
        return 0;

      case 4:
        printf("Enter the Element: ");
        scanf("%d",&ele);
        Insert_At_rear(q,&front,&rear,ele);
        break;

      case 5:
        Delete_at_rear(q,&front,&rear);
        break;
        
      default:
        printf("\nInvalid choice\n");
        break;
    }
  }
}
