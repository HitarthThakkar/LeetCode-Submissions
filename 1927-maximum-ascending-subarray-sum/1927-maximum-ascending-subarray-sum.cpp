class Solution
{
public:
    int maxAscendingSum(vector<int>& nums)
    {
        int n = nums.size();
        int ans = nums[0];
        int global_ans = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i - 1]) ans += nums[i];
            else ans = nums[i];
            global_ans = max(ans, global_ans);
        }
        return global_ans;
    }
};