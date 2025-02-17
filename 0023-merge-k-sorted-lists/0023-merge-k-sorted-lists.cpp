class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* answer = new ListNode(-1);
        ListNode* running = answer;
        while(true)
        {
            int i = 0, mind = -1, mini = 1e9;
            for(auto &head : lists)
            {
                if(head != NULL && head->val < mini) mini = head->val, mind = i;
                i++;
            }
            if(mind == -1) return answer->next;
            running->next = lists[mind];
            lists[mind] = lists[mind]->next;
            running = running->next;
        }
        return answer;
    }
};