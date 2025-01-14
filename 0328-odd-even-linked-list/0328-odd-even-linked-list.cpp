class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        int len = 0;
        if(head == NULL || head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(cur != NULL && cur->next != NULL)
        {
            ListNode* temp = cur->next;
            if(len % 2 == 0 && cur->next->next == NULL) cur->next = nxt;
            else cur->next = cur->next->next;
            cur = temp; len++;
        }
        if(len % 2 == 0) cur->next = nxt;
        return head;
    }
};