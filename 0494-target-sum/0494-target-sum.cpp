class Solution
{
private:
    int recur(int ind, vector<int> &nums, int target, int val)
    {
        if(ind == nums.size()) return (val == target);
        int one = recur(ind + 1, nums, target, val + nums[ind]);
        int two = recur(ind + 1, nums, target, val - nums[ind]);
        return (one + two);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        return recur(0, nums, target, 0);
    }
};