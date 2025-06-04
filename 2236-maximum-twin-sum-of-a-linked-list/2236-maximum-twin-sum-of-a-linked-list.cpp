class Solution
{
public:
    ListNode* reverseLL(ListNode* prev, ListNode* cur)
    {
        if(cur) {
            ListNode* nxt = cur->next; cur->next = prev;
            return reverseLL(cur, nxt);
        }
        else return prev;
    }
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
    int pairSum(ListNode* head)
    {
        ListNode* middle = middleNode(head);
        ListNode* head2 = reverseLL(NULL, middle);
        int res = 0;
        while(head != NULL && head2 != NULL)
        {
            res = max(res, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return res;
    }
};