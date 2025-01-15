class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while(hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target) hi = mid - 1;
            else lo = mid;
        }

        if(nums[hi] == target) return hi;
        else if(nums[lo] == target) return lo;
        return -1;

    }
};