class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(!head) return head;
        ListNode* cur = head;
        ListNode* prevTail;
        while(cur)
        {
            ListNode* nxt = cur->next;
            if(!nxt) return head;
            cur->next = nxt->next;
            nxt->next = cur;
            if(cur == head) head = nxt, prevTail = cur;
            else prevTail->next = nxt, prevTail = cur;
            cur = cur->next;
        }
        return head;
    }
};