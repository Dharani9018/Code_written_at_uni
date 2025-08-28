//24. swap nodes in pair
/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode *l=head, *r=head->next,*temp=NULL,*pre=l;
    temp = r->next;
    r->next = l;
    l->next = temp;
    head = r;
    while(pre->next && pre->next->next)
    {
        r = pre->next->next;
        l = pre->next;
        temp = r->next;
        pre->next = r;
        r->next = l;
        l->next = temp;
        pre = l;
    }
    return head;

}
