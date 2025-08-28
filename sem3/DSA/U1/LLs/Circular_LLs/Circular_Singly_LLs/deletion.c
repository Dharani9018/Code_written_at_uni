#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} N;

N *createNewnode(int data)
{
    N *newnode = (N*)malloc(sizeof(N));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;

}
void delete_At_first(N **last)
{
    if((*last)==NULL || (*last)->next == NULL)
    {
        return;
    }
    N *head =(*last)->next;
    if(head->next)
    {
        (*last)->next = head->next;
        free(head);
        head = NULL;
        return;
    }
    (*last)->next = *(last);
    free(head);
    head = NULL;
    return;
    
}

void delete_At_Last(N **last)
{ 
    if((*last)==NULL || (*last)->next == NULL)
    {
        free((*last));
        (*last)=NULL;
        return;
    }
    N *head = (*last)->next;
    N *temp = head;
    while(temp->next!=(*last))
    {
        if(temp==NULL)
        {
            return;
        }
        temp = temp->next;
    }
    temp->next = head;
    free(*last);
    (*last) = temp;
    return;
}

void delete_at_pos(int pos,N **last)
{
    if((*last)==NULL || (*last)->next == NULL || pos<=0 )
    {
        return;
    }
    else if(pos==1)
    {
        delete_At_first(last);
        return;
    }
    N *head =(*last)->next;
    N *temp = head;
    for(int i = 0; i<pos-2;i++)
    {
        if(temp==NULL || temp->next==NULL || temp == (*last))
        {
            return;
        }
        temp = temp->next;
    }
    if(temp->next==(*last))
    {
        delete_At_Last(last);
        return;
    }
    N *node = temp->next;
    temp->next = node->next;
    free(node);
    node = NULL;
    return;
}

void display(N **last)
{
    if((*last)==NULL || (*last)->next == NULL)
    {
        return;
    }
    N *temp = (*last)->next;
    printf("head -> ");
    while(temp!=(*last))
    {
        if(temp==NULL)
        {
            return;
        }
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d -> ",temp->data);
    printf("head\n");
    return;
}
int main()
{
    N *head = createNewnode(12);
    N *n1 = createNewnode(15);
    N *n2 = createNewnode(10);
    N *last = createNewnode(9);
    head->next = n1;
    n1->next = n2;
    n2->next = last;
    last->next = head;
    display(&last);
    printf("1: delete first node\n2: Delte last node\n3:Delete at position\n");
    int n = 0;
    int pos = 0;
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            delete_At_first(&last);
            break;
        case 2:
            delete_At_Last(&last);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d",&pos);
            delete_at_pos(pos,&last);
            break;
        default:
            printf("Invalid\n");
            break;
    }
    printf("After deletion: \n");
    display(&last);
}

