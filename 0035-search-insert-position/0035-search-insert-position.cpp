class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        if(hi == n - 1 && nums[hi] < target) return n;
        return hi;
    }
};