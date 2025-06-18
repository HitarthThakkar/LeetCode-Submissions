class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans = nums;
        // ans behaves as sfx also
        for(int i = n - 2; i > 0; i--) ans[i] *= ans[i + 1];
        // ans[0] is ans[1], as we know that for 0th index answer would be [1, n]'s products
        ans[0] = ans[1];
        int mul = 1; // pfx multiplication on the fly
        for(int i = 1; i < n - 1; i++) mul*=nums[i - 1], ans[i] = (mul * ans[i + 1]);
        // similar to 0th index case calculating seperately
        ans[n - 1] = mul * nums[n - 2];
        return ans;
    }
};