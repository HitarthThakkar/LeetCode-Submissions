class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;

        int l = 0;
        int r = 0;

        while(r < n)
        {
            if(nums[r] <= nums[l] * 1LL * k)
            {
                res = max(res, r - l + 1);
                r++;
            }
            else
            {
                l++;
            }
        }

        return (n - res);
    }
};