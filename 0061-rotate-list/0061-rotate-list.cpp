class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* curEnd = head;
        while(curEnd->next != NULL) curEnd = curEnd->next, len++;
        k %= len;
        if(k == 0) return head;
        int times = len - (k + 1);
        ListNode* newEnd = head;
        while(times--) newEnd = newEnd->next;
        ListNode* newHead = newEnd->next;
        newEnd->next = NULL;
        curEnd->next = head;
        return newHead;
    }
};