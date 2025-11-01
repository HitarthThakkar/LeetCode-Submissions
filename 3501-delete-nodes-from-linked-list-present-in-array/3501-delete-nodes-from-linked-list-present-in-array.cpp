class Solution
{
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> s;
        for(auto ele : nums) s.insert(ele);
        ListNode* ptr = head;
        while(ptr != NULL && ptr->next != NULL)
            if(s.find(ptr->next->val) != s.end()) ptr->next = ptr->next->next;
            else ptr = ptr->next;
        if(s.find(head->val) != s.end()) head = head->next;
        return head;
    }
};