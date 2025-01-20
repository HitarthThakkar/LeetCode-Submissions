class Solution
{
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> res(nums.size()); int i = 0, j = 1;
        for(auto ele : nums)
        {
            if(ele < 0) res[j] = ele, j += 2;
            else res[i] = ele, i += 2;
        }
        return res;
    }
};