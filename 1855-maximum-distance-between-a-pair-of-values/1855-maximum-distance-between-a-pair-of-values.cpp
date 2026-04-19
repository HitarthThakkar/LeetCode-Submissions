class Solution
{
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int j = 0, res = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            while(j < nums2.size() && nums2[j] >= nums1[i]) j++;
            if(j == nums2.size()) return max(j - i - 1, res);
            if(j > 0) j--;
            res = max(res, j - i);
        }
        return res;
    }
};