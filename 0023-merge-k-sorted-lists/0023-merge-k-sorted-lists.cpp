
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* result = new ListNode(-1);
        ListNode* answer = result;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto head : lists) if(head) pq.push(head);
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node->next) pq.push(node->next);
            result->next = node;
            result = result->next;
        }
        return answer->next;
    }
};