/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
  struct ListNode *cur = head ,*temp= head;
  struct ListNode *pre = NULL;
  int count = 0;
  while(temp!=NULL)
  {
    count++; 
    temp = temp->next;
  }
  if(count!=n)
  {
    count = count - n;
  }
  else
  {
    head = cur->next;
    free(cur);
    cur = NULL;
    return head;
  }

  while(count)
  {
    pre = cur;
    cur = cur->next;
    count--;
  }
  if(pre==NULL)
  {
    free(head);
    head = NULL;
    return head;
  }
  pre->next = cur->next;
  free(cur);
  cur=NULL;
  return head;
}
