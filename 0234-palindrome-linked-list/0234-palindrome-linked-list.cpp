
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
    bool isPalindrome(ListNode* head)
    {
        ListNode* fastptr = head;
        ListNode* slowptr = head;

        while(fastptr && fastptr->next)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        ListNode* secondHead;

        if(fastptr == NULL) secondHead = reverseLL(NULL, slowptr);
        else secondHead = reverseLL(NULL, slowptr->next);

        while(secondHead && head)
        {
            if(head->val != secondHead->val) return false;
            head = head->next;
            secondHead = secondHead->next;
        }

        return true;
    }
};