class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int res = 0;
        while(head)
        {
            res *= 2;
            if(head->val == 1) res++;
            head = head->next;
        }
        return res;
    }
};