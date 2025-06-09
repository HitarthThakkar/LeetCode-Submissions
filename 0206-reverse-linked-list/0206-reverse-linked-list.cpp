class Solution
{
private:
    ListNode* reverseLL(ListNode* prev, ListNode* cur)
    {
        if(cur) {
            ListNode* nxt = cur->next; cur->next = prev;
            return reverseLL(cur, nxt);
        }
        else return prev;
    }
public:
    ListNode* reverseList(ListNode* head)
    {
        return reverseLL(NULL, head);
    }
};