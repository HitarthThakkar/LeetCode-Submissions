class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int preva = -1e6;
        vector<vector<int>> v;
        int ans = 1e6, actual_ans = -69;

        for(int i = 0; i < n - 2; i++)
        {
            if(nums[i] != preva)
            {
                int lo = i + 1;
                int hi = n - 1;
                int cur_tgt = (target - nums[i]);
                int pb = nums[lo];
                int pc = nums[hi];
                while(hi > lo)
                {
                    int sum = nums[lo] + nums[hi];

                    if(abs(cur_tgt - sum) < ans)
                    {
                        ans = abs(cur_tgt - sum);
                        actual_ans = sum + nums[i];
                    }

                    if(sum < cur_tgt)
                    {
                        while(lo < n && nums[lo] == pb) lo++;
                        if(lo < n) pb = nums[lo];
                    }
                    else if(sum > cur_tgt)
                    {
                        while(hi > i && nums[hi] == pc) hi--;
                        if(hi > i) pc = nums[hi];
                    }
                    else
                    {
                        return target;
                    }
                }
                preva = nums[i];
            }
        }
        return actual_ans;
    }
};