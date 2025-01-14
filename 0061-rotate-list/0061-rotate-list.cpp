class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* cur = head;
        while(cur->next) { cur = cur->next; len++; }
        k %= len;
        if(k == 0) return head;
        int times = len - (k + 1);
        ListNode* newEnd = head;
        ListNode* newHead = head;
        while(times--) newEnd = newEnd->next;
        newHead = newEnd->next;
        newEnd->next = NULL;
        cur->next = head;
        return newHead;
    }
};