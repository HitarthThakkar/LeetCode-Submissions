class Solution
{
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;
        for(auto e : nums1)
        {
            if(e == 0) z1++;
            else s1 += e;
        }
        for(auto e : nums2)
        {
            if(e == 0) z2++;
            else s2 += e;
        }
        if(z1 == 0 && z2 == 0)
        {
            if(s1 == s2) return s1;
            else return -1;
        }
        else if(z1 == 0)
        {
            if(s2 + z2 > s1) return -1;
            return s1;
        }
        else if(z2 == 0)
        {
            if(s1 + z1 > s2) return -1;
            return s2;
        }
        else
        {
            return max(s1 + z1, s2 + z2);
        }
        return -1;
    }
};