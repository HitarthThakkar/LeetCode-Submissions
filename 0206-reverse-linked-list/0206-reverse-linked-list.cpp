class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while(nxt)
        {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        return cur;
    }
};