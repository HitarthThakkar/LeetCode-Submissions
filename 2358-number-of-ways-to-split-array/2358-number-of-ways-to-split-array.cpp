class Solution
{
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long> pfx(n, nums[0]), sfx(n, nums[n - 1]);
        for(int i = 1; i < n; i++) pfx[i] = pfx[i - 1] + nums[i];
        for(int i = n - 2; i >= 0; i--) sfx[i] = sfx[i + 1] + nums[i];
        int ans = 0;
        for(int i = 0; i < n - 1; i++) if(pfx[i] >= sfx[i + 1]) ans++;
        return ans;
    }
};