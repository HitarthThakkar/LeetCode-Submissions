class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        if(head->next == NULL) return NULL;        
        ListNode* prev = NULL;
        ListNode *slowptr = head;
        ListNode *fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL)
        {
            prev = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        if(prev && prev->next) prev->next = prev->next->next;
        return head;
    }
};