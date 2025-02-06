class Solution
{
public:
    int tupleSameProduct(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                mp[nums[i] * nums[j]]++;
        int ans = 0;
        for(auto ele : mp)
            ans += (4 * ((ele.second) * (ele.second - 1)));
        return ans;
    }
};