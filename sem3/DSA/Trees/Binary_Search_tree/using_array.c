#include<stdio.h>

void insert(int *t,int x)
{
  int i = 0;
  while(t[i]!=-1)
  {
    if(x<t[i])
      i = 2*i+1;
    else
      i = 2*i+2;
  }
  t[i] = x;
}
void inorder(int *t,int i)
{
  if(t[i]==-1)
    return;
  inorder(t,2*i+1);
  printf("%d\t",t[i]);
  inorder(t,2*i+2);
}
void preorder(int *t,int i)
{
  if(t[i]==-1)
    return;
  printf("%d\t",t[i]);
  preorder(t,2*i + 1);
  preorder(t,2*i + 2);
}

void postorder(int *t, int i)
{
  if(t[i]==-1)
    return;
  postorder(t,2*i + 1);
  postorder(t,2*i + 2);
  printf("%d\t",t[i]);
}

int main()
{
  int t[100];
  int ch,x,i;
  for(i=0;i<100;i++)
  {
    t[i]=-1;
  }
  while(1)
  {
    printf("\n1.Insert\n2.preorder\n3.inorder\n4.postorder\n5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the element: ");
        scanf("%d",&x);
        insert(t,x);
        break;
      case 2: preorder(t,0);break;
      case 3: inorder(t,0);break;
      case 4: postorder(t,0);break;
      case 5: return 0;
      default: printf("\nInvalid Option\n");
    }
  }
}
