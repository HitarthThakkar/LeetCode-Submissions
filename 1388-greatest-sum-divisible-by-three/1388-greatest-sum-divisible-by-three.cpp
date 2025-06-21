class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int result = accumulate(nums.begin(), nums.end(), 0);
        if(result % 3 == 0) return result;

        if(result % 3 == 1)
        {
            // minimum of these two options
            // 1] minimum element having 1 as remainder
            // 2] two smallest having 2 as remainder
            int mini = INT_MAX;
            for(auto e : nums) if(e % 3 == 1 && e < mini) mini = e;
            priority_queue<int> pq;
            for(auto e : nums)
                { if(e % 3 == 2) pq.push(e); if(pq.size() > 2) pq.pop(); }
            if(pq.size() < 2) return result - mini;
            else {
                int op1 = result - mini;
                int op2 = result;
                while(!pq.empty()) { op2 -= pq.top(); pq.pop(); }
                return max(op1, op2);
            }
        }
        else
        {
            // minimum of these two options
            // 1] minimum element having 2 as remainder
            // 2] two smallest having 1 as remainder
            int mini = INT_MAX;
            for(auto e : nums) if(e % 3 == 2 && e < mini) mini = e;
            priority_queue<int> pq;
            for(auto e : nums)
                { if(e % 3 == 1) pq.push(e); if(pq.size() > 2) pq.pop(); }
            if(pq.size() < 2) return result - mini;
            else {
                int op1 = result - mini;
                int op2 = result;
                while(!pq.empty()) { op2 -= pq.top(); pq.pop(); }
                return max(op1, op2);
            }
        }
        return -69872;
    }
};