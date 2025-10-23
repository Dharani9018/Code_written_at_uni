//directed
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
  int data;
  struct node *link;
} NODE;

void insert(NODE *a[],int i,int j)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = j;
  newnode->link = NULL;
  NODE *cur = a[i];
  if(cur!=NULL)
  {
    a[i] = newnode;
    return;
  }
  while(cur->link!=NULL)
  {
    cur = cur->link;
  }
  cur->link = newnode;  
}
void display(NODE *a[],int n)
{
  for(int i = 0;i<n;i++)
  {
    NODE *cur = a[i];
    {
      printf("%d\t",i);
      while(cur!=NULL)
      {
        printf("%d\t",cur->data);
        cur = cur->link;
      }
    }
  }
}
void create_graph(NODE *a[],int n)
{
  int i,j;
  for(int i = 0;i<n;i++)
  {
    a[i]=NULL;
  }
  while(1)
  {
    printf("Enter the source and destination: ");
    scanf("%d %d",&i,&j);
    if(i<0 || j<0 || i>=n || j>=n)
    {
      break;
    }
    insert(a,i,j);
  }
}
//out degree:
int outdegree(NODE *a[],int v,int n)
{
  int count = 0;
  for(int i = 0;i<n;i++)
  {
    if(v==a[i]->data)
    {
      NODE *cur = a[i];
      while(cur!=NULL)
      {
        cur = cur->link;
        count++;
      }
    }
  }
  return count;
}
int indegree(NODE *a[],int v,int n)
{
  int count = 0;
  for(int i = 0;i<n;i++)
  {
    NODE *cur = a[i]
    while(cur!=NULL)
    {
      if(cur->data==v)
      {
        count++;
      }
      cur=cur->link;
    }
  }
  return count;
}
int main()
{
  int n,v;
  NODE *a[MAX];
  printf("\nVertices: ");
  scanf("%d",&n);
  create_graph(a,n);
  display(a,n);
  printf("Vertex to calculate indegree\n");
  scanf("%d",&v);
  outdegree(a,v,n);
  return 0;
}
