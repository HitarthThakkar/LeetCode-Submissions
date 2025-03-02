class Solution
{
public:
    int recur(int lli, int ptr, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ptr > nums.size() - 2)
        {
            int mex = nums[lli];
            while (ptr < nums.size()) mex = max(mex, nums[ptr++]);
            return mex;
        }
        if (dp[lli][ptr] != 2e9) return dp[lli][ptr];
        dp[lli][ptr] = min(dp[lli][ptr], max(nums[ptr],nums[ptr+1]) + recur(lli,ptr+2,nums,dp));
        dp[lli][ptr] = min(dp[lli][ptr], max(nums[lli], nums[ptr+1]) + recur(ptr,ptr+2,nums,dp));
        dp[lli][ptr] = min(dp[lli][ptr], max(nums[lli], nums[ptr]) + recur(ptr+1,ptr+2,nums,dp));
        return dp[lli][ptr];
    }

    int minCost(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n <= 3)
        {
            int mex = *max_element(nums.begin(), nums.end());
            int mean = *min_element(nums.begin(), nums.end());
            if (nums.size() == 2) return mex; return (mex + mean);
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 2e9));
        return recur(0, 1, nums, dp);
    }
};