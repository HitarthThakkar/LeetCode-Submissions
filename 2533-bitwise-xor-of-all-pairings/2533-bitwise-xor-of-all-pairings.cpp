class Solution
{
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(); int m = nums2.size(); int ans = 0;
        if((n & 1) && (m & 1))
        {
            for(auto ele : nums1) ans ^= ele;
            for(auto ele : nums2) ans ^= ele;
        }
        else if(n & 1)
        {
            for(auto ele : nums2) ans ^= ele;
        }
        else if(m & 1)
        {
            for(auto ele : nums1) ans ^= ele;
        }
        return ans;
    }
};