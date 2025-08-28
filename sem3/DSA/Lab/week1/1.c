/*Sample Input 0

5
4 1 8 4 5
6
5 6 1 8 4 5
2 
3
Sample Output 0

8

The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
*/

//1.

struct ListNode *getIntersectionNode(struct ListNode *headA,struct ListNode *headB) 
{
// Your code goes here
    if(headA==NULL || headB==NULL)
    {
        return NULL;
    }
    struct ListNode *l1 = headA;
    struct ListNode *l2 = headB;
    while(l1!=NULL)
    {
        l2 = headB;
        while(l2!=NULL)
        { 
            if(l1==l2)
            {
                return l1;
            }
            l2 = l2->next;
        }
        l1 = l1->next;
    }
    return NULL;
}

//2.

struct ListNode *getIntersectionNode(struct ListNode *headA,struct ListNode *headB) 
{
// Your code goes here
    if(headA==NULL || headB==NULL)
    {
        return headA;
    }
    struct ListNode *l1 = headA,*cur1 = headA;
    struct ListNode *l2 = headB,*cur2 = headB;
    int m=0,n=0,dif=0;
    
    while(l1!=NULL || l2!=NULL)
    {
        if(l1!=NULL)
        { 
            l1 = l1->next;
            n++;
        }
        if(l2!=NULL)
        {
            m++;
            l2 = l2->next;
        }

    }
    if(m>n)
    {
        dif = m-n;
        while(dif && cur2)
        {
            cur2 = cur2->next;
            dif--;
        }
    }
    if(m<n)
    {
        dif = n-m;
        while(dif && cur1)
        {
            cur1 = cur1->next;
            dif--;   
        }
    }
    if(cur1 && cur2)
    {     
        while(cur1!=NULL && cur2!=NULL)
        {
            if(cur1==cur2)
            {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    return NULL;
}




