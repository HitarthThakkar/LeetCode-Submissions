class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int ii = upper_bound(nums.begin(), nums.end(), nums[i] * 1LL * k) - nums.begin();
            ii--;
            res = max(res, ii - i + 1);
        }

        return (nums.size() - res);
    }
};