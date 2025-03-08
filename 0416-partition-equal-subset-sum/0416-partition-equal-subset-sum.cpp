class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int target = sum / 2;
        vector<bool> prev(target + 1, false), cur(target + 1, false);
        prev[0] = true;
        cur[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int ind = 1; ind < nums.size(); ind++)
        {
            for(int k = 1; k < target + 1; k++)
            {
                bool notTake = prev[k];
                bool take = false;
                if(nums[ind] <= k) take = prev[k - nums[ind]];
                cur[k] = (take || notTake);
            }
            prev = cur;
        }

        return prev[target];
    }
};