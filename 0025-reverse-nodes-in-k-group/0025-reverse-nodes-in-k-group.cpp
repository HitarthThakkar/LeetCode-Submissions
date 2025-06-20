class Solution
{
public:
    pair<ListNode*, ListNode*> reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return {prev, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(!head->next || k == 1) return head;
        ListNode* toBeReturned;
        ListNode* prevTail;
        ListNode* curHead = head;

        while(curHead)
        {
            int kk = k - 1;
            ListNode* curTail = curHead;
            while(kk--)
            {
                if(curTail) curTail = curTail->next;
                else {
                    prevTail->next = curHead;
                    return toBeReturned;
                }
            }
            if(!curTail) {
                prevTail->next = curHead;
                return toBeReturned;
            }
            ListNode* tobeHead = curTail->next;
            curTail->next = NULL;
            pair<ListNode*, ListNode*> toBePrev = reverseList(curHead);
            if(curHead == head)
            {
                toBeReturned = toBePrev.first;
                prevTail = toBePrev.second;
            }
            else
            {
                prevTail->next = toBePrev.first;
                prevTail = toBePrev.second;
            }
            curHead = tobeHead;
        }

        return toBeReturned;
    }
};