class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size(), lo = 0, hi = n - 1;
        int ans = 1e5;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(nums[mid] >= nums[lo])
            {
                ans = min(ans, nums[lo]);
                lo = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                hi = mid - 1;
            }
        }
        return ans;
    }
};