#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
typedef struct node
{
  char data;
  struct node *left,*right;
} NODE;

int eval(NODE *root)
{
  int num;
  switch (root->data)
  {
    case '+': 
      return(eval(root->left) + eval(root->right));
      
      break;
    case '-':
      return(eval(root->left) - eval(root->right));
      break;
    case '*':
      return(eval(root->left)*eval(root->right));
      break;
    case '/':
      return(eval(root->left)/eval(root->right));
      break;
    case '^':
      return (int)(pow(eval(root->left),eval(root->right)));
      break;
    default:
      if(isalpha(root->data))
      {
        printf("value of %c= ",root->data);
        scanf("%d",&num);
        return num;
      }
      else
      { 
        return(root->data-'0');
      }
  }
}
int main()
{
  NODE *root = NULL;
  NODE  *temp;
  int top = -1;
  NODE *stack[MAX];
  int ele,i=0;
  char postfix[MAX],symb;
  printf("\nEnter the expression\n");
  scanf("%s",postfix);
  while((symb=postfix[i])!='\0')
  {
    temp = malloc(sizeof(NODE));
    temp->data = symb;
    temp->left=temp->right = NULL;
    if(isalnum(symb))
    {
      stack[++top] = temp;
    }
    else
    {
      temp->right = stack[top--];
      temp->left = stack[top--];
      stack[++top] = temp;
    }
    i++;
  }
  root = stack[top];
  int result = eval(root);
  printf("result: %d\n",result);
}
