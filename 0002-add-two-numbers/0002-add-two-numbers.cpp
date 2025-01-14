class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ansHead = new ListNode();
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* curr = ansHead;
        while(p1 != NULL && p2 != NULL)
        {
            int sum = p1->val + p2->val + carry;
            if(sum > 9)
            {
                carry = (sum / 10);
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }

            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            p1 = p1->next;
            p2 = p2->next;

        }
        while(p1 != NULL)
        {
            int sum = p1->val + carry;
            if(sum > 9)
            {
                carry = (sum / 10);
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            p1 = p1->next;
        }
        while(p2 != NULL)
        {
            int sum = p2->val + carry;
            if(sum > 9)
            {
                carry = (sum / 10);
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            p2 = p2->next;
        }

        if(carry > 0)
        {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return ansHead->next;
    }
};