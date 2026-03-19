class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;

        // Monotonic Deque - (stack + queue in one ahh problem)
        deque<int> dq;

        for(int i = 0; i < k; i++)
        {
            // Cleaning 'trash'
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);
        }

        // Monotonic (first == biggest)
        res.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++)
        {
            int lvi = i - k + 1;    // Least Valid Index, does window things
            while(!dq.empty() && dq.front() < lvi) dq.pop_front();

            // Cleaning 'trash'
            while(dq.size() > 0 && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            res.push_back(nums[dq.front()]);    // Monotonic (first == biggest)
        }

        return res;
    }
};