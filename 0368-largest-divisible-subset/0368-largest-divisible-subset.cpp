class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[i].size() < dp[j].size() + 1)
                    {
                        dp[i] = dp[j];
                        dp[i].push_back(nums[i]);
                    }
                }
            }
            if(dp[i].size() == 0)
            {
                dp[i].push_back(nums[i]);
            }
        }
        vector<int> ans;
        for(auto e : dp) if(e.size() > ans.size()) ans = e;
        return ans;
    }
};