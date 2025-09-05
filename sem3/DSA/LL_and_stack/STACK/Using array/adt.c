#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct STACK
{
  int top;
  int a[MAX];
} stack;

void display(stack *ptr)
{
  if(ptr->top==-1)
  {
    printf("Stack is empty-> underflow\n");
    return;
  }
  printf("\n");
  for(int i = 0; i<ptr->top; i++)
  {
    printf("%d\n",ptr->a[i]);
  }
  printf("\n");
  return;
}

void pop(stack *ptr)
{
  if(ptr->top==-1)
  {
    printf("Stack is empty-> underflow\n");
    return;
  }
  --(ptr->top);
  return;


}

void push(stack *ptr, int ele)
{
  if(ptr->top==MAX-1)
  {
    printf("Overflow");
    return;
  }
  ptr->a[++(ptr->top)] = ele;
  return;
}

int main()
{
  int ele,ch;
  stack *ptr,s;
  ptr = &s;
  ptr->top = -1;
  while(1)
  {
    printf("\n1.push\n2.pop\n3.display\n4.Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch (ch) 
    {
      case 1:
      printf("Enter the element: ");
      scanf("%d",&ele);
      push(ptr,ele);
      break;

      case 2:
      pop(ptr);
      break;

      case 3:
      display(ptr);
      break;
      
      case 4:
      exit(0);
      break;

      default:
      printf("Invalid choice\n");
      break;
    }
  }
  return 0;
}
