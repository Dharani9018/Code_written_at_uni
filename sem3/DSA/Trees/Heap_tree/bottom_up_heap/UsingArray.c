#include<stdio.h>
# define MAX 25
void bottom_up(int *h,int n)
{
  int k,i,j,key;
  for(k=(n-1)/2;k>=0;k--)
  {
    j = k;
    key = h[j];
    i = 2*j+1; //index of left child
    while(i<=n) //while left child exists
    {
      if((i+1)<=n && h[i+1]>h[i]) //if right child exists and is greater than left child.
      {
        i++; //use right child  
      }
    
      if(h[i]>key) //if child is greater than key, move child up
      {
        h[j] = h[i];
        j = i;
        i = 2*j+1; //move to left child.
      }
      else
      {
        break;
      }
    }
    h[j] = key;
  }
}

int main()
{
  int h[MAX], n, x;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  printf("Enter the elements: \n");

  for(int i = 0;i<n;i++)
  {
    scanf("%d",h+i);
  }
  printf("\nBefore heapify\n");
  for(int i = 0;i<n;i++)
  { 
    printf("%d\t",h[i]);
  }
  bottom_up(h,n-1);
  printf("\nAfter heapify:\n");
  for(int i = 0;i<n;i++)
  { 
    printf("%d\t",h[i]);
  }
  return 0;
}
