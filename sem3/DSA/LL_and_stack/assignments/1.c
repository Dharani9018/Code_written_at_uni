/*DMA*/
/* Multipy 2 matrices */


#include<stdio.h>
#include<stdlib.h>
void display(int **a,int rows,int col)
{
  printf("\n");
  for(int i = 0;i<rows;i++)
  {
    for(int j = 0;j<col;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}
int **createMatrix(int rows,int cols)
{
  int **N = malloc(rows*sizeof(int));
  for(int i = 0;i<rows;i++)
  {
    N[i] = malloc(sizeof(int)*cols);
  }
  return N;
}
int **Multipy(int **a,int **b,int rows,int cols)
{
  int **p = createMatrix(rows,cols);
  for(int i = 0;i<rows;i++)
  {  
    for(int j = 0;j<cols;j++)
    {
      int sum = 0;
      for(int k = 0;k<rows;k++)
      {
        sum = sum + ((a[i][k])*b[k][j]);
      }
      p[i][j] = sum;
    }
  }
  return p;
}

int main()
{
  int **a,**b,rows,col,**p;
  printf("Enter the no. of rows and columns: ");
  scanf("%d %d",&rows,&col);
  a = createMatrix(rows,col);
  b = createMatrix(rows,col);
  printf("Enter the elements in matix a and b:\n");
  for(int i = 0;i<rows;i++)
  {
    for(int j = 0;j<col;j++)
    {
      printf("Element [%d][%d]: \n",i+1,j+1);
      printf("a: ");
      scanf("%d",&a[i][j]);
      printf("b: ");
      scanf("%d",&b[i][j]);
    }
  }
  printf("Matrix a:\n");
  display(a,rows,col);
  printf("Matrix b:\n");
  display(b,rows,col);
  p = Multipy(a,b,rows,col);
  printf("After multipying:axb\n");
  display(p,rows,col);
}

/* Swapping 2 no.s using bitwise operator */




