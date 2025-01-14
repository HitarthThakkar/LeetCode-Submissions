class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slowptr = head;
        ListNode *fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
    }
};