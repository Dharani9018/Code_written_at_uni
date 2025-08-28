/*Sample Input 0

6
1 4 3 2 5 2
3
Sample Output 0

1 2 2 4 3 5
*/

struct ListNode* partition(struct ListNode* head, int x) {
    if (!head) return NULL;

    struct ListNode less_List = {0, NULL};   // Creating structure variable for the 2 lists  val = 0 and next = NULL. list for < x
    struct ListNode greater_List = {0, NULL}; // list for >= x

    struct ListNode* less_tail = &less_List; //Creating structure pointers for the 2 lists;
    struct ListNode* greater_tail = &greater_List;
    struct ListNode *cur = head;
    
    while(cur)
    {
        if(x>cur->value)
        {
            less_tail->next = cur;
            less_tail = cur; //moving the less_tail pointer it doesnt point to less_List anymore.
        }
        else
        {
            greater_tail->next = cur;
            greater_tail = cur;
        }
        cur = cur->next;
    }
    //making the less_tail point to start of greater_List.
    less_tail->next = greater_List.next;
    greater_tail->next = NULL;
    return less_List.next;
   }

