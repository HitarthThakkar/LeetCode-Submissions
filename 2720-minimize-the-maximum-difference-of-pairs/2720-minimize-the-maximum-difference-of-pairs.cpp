class Solution
{
public:
    bool good(int mexDiff, int p, vector<int> &nums)
    {
        if(p <= 0) return true;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] <= mexDiff)
            {
                p--;
                i++;
                if(p <= 0) return true;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p)
    {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back() - nums[0];
        int res = hi;

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(good(mid, p, nums))
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return res;
    }
};