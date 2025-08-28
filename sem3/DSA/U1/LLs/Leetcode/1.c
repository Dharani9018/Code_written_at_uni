/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode *head = NULL; // new head
    struct ListNode *pre = NULL;

    if (!list1) return list2; // !list1 means list1 == NULL (no nodes left in list1)
    if (!list2) return list1;

    // Choose the smaller head first
    if (list1->val <= list2->val) 
    {
        head = list1;
    } 
    else 
    {
        head = list2;
        list2 = list2->next;
        head->next = list1;
        pre = head;
        list1 = head->next;
    }

    while (list1 && list2) 
    {
        if (list1->val <= list2->val) 
        {
            pre = list1;
            list1 = list1->next;
        } 
        else 
        {
            struct ListNode* temp = list2->next;
            pre->next = list2;
            list2->next = list1;
            pre = list2;
            list2 = temp;
        }
    }

    if (list2) 
    {
        pre->next = list2;
    }

    return head;
}

