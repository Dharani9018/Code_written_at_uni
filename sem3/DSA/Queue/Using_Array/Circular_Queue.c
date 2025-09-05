#include<stdio.h>

#define MAX 5

/*Empty condition:
  front=rear=-1
*/

/*Overflow Condition:
* (front==0 && rear==MAX-1) || (front == rear + 1)
*/
void Enqueue(int *q,int *rear,int *front,int ele)
{
  if((*front==0 && *rear==MAX-1) || (*front == *rear + 1))
  {
    printf("\nOverflow\n");
    return;
  }
  if(*front==-1)
  {
    *front = 0;
  }
  *rear = (*rear + 1)%MAX;
  q[*rear]=ele;
  return;
}

void Dequeue(int *q,int *rear,int *front)
{
  if((*front)==-1)
  {
    printf("Underflow\n");
    return;
  }

  if((*front)==(*rear))
  {
    printf("\nDeleted: %d\n",q[*rear]);
    *front=-1;
    *rear = -1;
    return;
  }
  printf("\ndeleted: %d\n",q[*front]);
  (*front) = ((*front)+ 1)%MAX;

  return;
}
void display(int *q,int front,int rear)
{
  if(rear==-1)
  {
    printf("\nUnderflow\n");
    return;
  }
  printf("\n");
  for(int i = front;i!=rear;i = (i+1)%MAX)
  {
    printf("%d ",q[i]);
  }
  printf("%d\n",q[rear]);
  return;
}

int main()
{
  int q[5],front=-1,rear=-1,ch,ele;

 while (1) 
  {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Enqueue(q,&rear,&front,ele);
        break;
      case 2:
        Dequeue(q,&rear,&front);
        break;
      case 3:
        display(q,front,rear);
        break;
      case 4:
        return 0;

      default:
        printf("\nInvalid choice\n");
        break;
    }
  }
}
    



