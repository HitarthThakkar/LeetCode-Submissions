class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int res = 0;
        int l = 0;
        int r = 0;
        int zc = 0;  // kitne zero hai abhi window me

        while(r < nums.size())
        {
            if(nums[r] == 0)
            {
                while(zc == k) { if(nums[l] == 0) zc--; l++; }
                zc++;
            }
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};