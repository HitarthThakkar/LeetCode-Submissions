class Solution
{
private:
    int recur(int ind, vector<int> &nums, int target, int val, vector<vector<int>> &dp)
    {
        if(ind == nums.size()) return ((val == target) || (val == (target * -1)));
        int conval, conval2;
        conval = (val + nums[ind]); if(conval < 0) conval *= -1;
        if(dp[ind + 1][conval] == -1)
            dp[ind + 1][conval] = recur(ind + 1, nums, target, val + nums[ind], dp);
        conval2 = (val - nums[ind]); if(conval2 < 0) conval2 *= -1;
        if(dp[ind + 1][conval2] == -1)
            dp[ind + 1][conval2] = recur(ind + 1, nums, target, val - nums[ind], dp);
        return (dp[ind + 1][conval] + dp[ind + 1][conval2]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp((n + 1), vector<int> (1001, -1));
        if(target == 0) return recur(0, nums, target, 0, dp);
        else if(target < 0) target *= -1;
        return ((recur(0, nums, target, 0, dp) / 2));
    }
};