#include<stdio.h>
//Inserting in ascending order.
# define MAX 5
void Enqueue(int *q,int *rear,int ele)
{
  if((*rear)==MAX-1)
  {
    printf("\nOverflow\n");
    return;
  }
  int j = *rear;
  while(j>=0 && ele<q[j])
  {
    q[j+1] = q[j];
    j--;
  }
  q[j+1] = ele;
  *rear = *rear + 1;
  return;
}

void Dequeue(int *q,int *front,int rear)
{
  if(*front>rear)
  {
    printf("\nUnderflow\n");
    return;
  }
  printf("\ndeleted: %d\n",q[*front]);
  (*front) = *front + 1;
  return;
}

void display(int *q,int front,int rear)
{
  if(front>rear)
  {
    printf("\nUnderflow\n");
    return;
  }
  printf("\n");
  for(int i = front;i<=rear;i++)
  {
    printf("%d\t",q[i]);
  }
  printf("\n");
  return;
}

int main()
{
  int q[5],front=0,rear=-1,ch,ele;

while (1) 
  {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Enqueue(q,&rear,ele);
        break;
      case 2:
        Dequeue(q,&front,rear);
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
