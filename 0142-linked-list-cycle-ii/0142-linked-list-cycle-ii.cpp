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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr)
            {
                ListNode* newptr = head;
                while(newptr != slowptr)
                {
                    newptr = newptr->next;
                    slowptr = slowptr->next;
                }
                return newptr;
            }
        }
        return nullptr;
    }
};