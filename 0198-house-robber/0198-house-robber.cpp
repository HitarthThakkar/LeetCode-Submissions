class Solution
{
public:

    int recur(int i, bool prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int p1 = 0, p2 = 0;
        if(!prev) p1 = nums[i] + recur(i + 1, true, nums, dp);
        p2 = recur(i + 1, false, nums, dp);
        return dp[i][prev] = max(p1, p2);
    }

    int rob(vector<int>& nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int> (2, -1));
        return recur(0, false, nums, dp);
    }
};