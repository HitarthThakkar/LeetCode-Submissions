class Solution
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        vector<int> xorvec;
        int xr = nums[0];
        for(int i = 1; i < nums.size(); i++) xorvec.push_back(xr), xr ^= nums[i];
        xorvec.push_back(xr);
        reverse(xorvec.begin(), xorvec.end());
        long long int target = pow(2, maximumBit) - 1;
        vector<int> ans;
        for(auto ele : xorvec) ans.push_back(ele ^ target);
        return ans;
    }
};