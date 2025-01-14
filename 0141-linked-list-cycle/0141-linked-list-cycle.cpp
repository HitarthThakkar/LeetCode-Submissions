class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slowptr = head;
        ListNode *fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr) return true;
        }
        return false;
    }
};