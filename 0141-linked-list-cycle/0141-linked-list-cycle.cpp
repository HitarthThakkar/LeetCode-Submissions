/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowptr = head;
        ListNode *fastptr = head;
        if(head == NULL)
        {
            return false;
        }
        while(fastptr != NULL)
        {
            if(fastptr->next == NULL)
            {
                return false;
            }
            else
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next->next;
            }
            if(slowptr == fastptr)
            {
                return true;
            }
        }
        return false;
    }
};